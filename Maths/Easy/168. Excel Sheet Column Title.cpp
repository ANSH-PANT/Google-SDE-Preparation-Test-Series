/*
Time Complexity: O(log(columnNumber))
Space Complexity: O(log(columnNumber))
*/

char* convertToTitle(int columnNumber) {
    int quotient = columnNumber;
    int mod = columnNumber;
    int count = 0;
    while (quotient > 26) {
        if (quotient % 26 == 0) {
            quotient = quotient - 26;
        }
        quotient = quotient / 26;
        count++;
    }
    char* array = (char*)malloc(sizeof(char) * (count + 2));
    quotient = columnNumber;
    array[count + 1] = '\0';
    if (count == 0) {
        array[0] = 'A' + columnNumber - 1;
    } else if (count > 0) {
        quotient = columnNumber;
        while (count > 0) {
            mod = quotient % 26;
            if (mod == 0) {
                array[count] = 'Z';
                quotient = quotient - 26;
            } else {
                array[count] = 'A' + mod - 1;
            }
            quotient = quotient / 26;
            count--;
        }
        array[count] = 'A' + quotient - 1;
    }
    return array;
}
