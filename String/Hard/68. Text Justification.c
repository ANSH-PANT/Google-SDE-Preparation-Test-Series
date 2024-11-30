/*
Time Complexity: O(n⋅maxWidth)
Space Complexity: O(n⋅maxWidth)
*/

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int wordLengths[wordsSize];
    for (int i = 0; i < wordsSize; i++) {
        int temp = strlen(words[i]);
        wordLengths[i] = temp;
    }
    int i = 1, running, total = 0, next = 0;
    int placements[wordsSize * 2];
    while (i < wordsSize) {
        running = wordLengths[i - 1] + 1;
        while (i < wordsSize && running - 1 <= maxWidth) {
            running += wordLengths[i] + 1;
            i++;
        }
        if (running - 1 > maxWidth) {
            running -= wordLengths[i - 1] + 1;
        } else {
            i++;
        }
        placements[next] = i - total - 1;
        placements[next + 1] = maxWidth + 1 - running;
        total = i - 1;
        next += 2;
    }
    if (wordsSize - total > 0) {
        placements[next] = wordsSize - total;
        placements[next + 1] = 0;
        next += 2;
    }
    char** solution = malloc(sizeof(char*) * (next / 2));
    char construct[maxWidth + 1];
    int prior = 0;
    for (int j = 0; j < next - 2; j += 2) {
        int sharedWhitespace;
        int extraWhitespace;
        if (placements[j] > 1) {
            sharedWhitespace = placements[j + 1] / (placements[j] - 1);
            extraWhitespace = placements[j + 1] % (placements[j] - 1);
        }
        int k = 0;
        int current = 0;
        while (current < placements[j]) {
            for (int m = 0; m < wordLengths[current + prior]; m++) {
                construct[k] = words[current + prior][m];
                k++;
            }
            current++;
            if (current < placements[j]) {
                for (int m = 0; m < sharedWhitespace + 1; m++) {
                    construct[k] = ' ';
                    k++;
                }
                if ((current - 1) % (placements[j] - 1) < extraWhitespace) {
                    construct[k] = ' ';
                    k++;
                }
            }
        }
        while (k < maxWidth) {
            construct[k] = ' ';
            k++;
        }
        prior += current;
        construct[maxWidth] = '\0';
        solution[j / 2] = strdup(construct);
    }
    int k = 0;
    int current = 0;
    while (current < placements[next - 2]) {
        for (int m = 0; m < wordLengths[current + prior]; m++) {
            construct[k] = words[current + prior][m];
            k++;
        }
        if (k < maxWidth) {
            construct[k] = ' ';
            k++;
        }
        current++;
    }
    while (k < maxWidth) {
        construct[k] = ' ';
        k++;
    }
    construct[maxWidth] = '\0';
    solution[next / 2 - 1] = strdup(construct);
    *returnSize = next / 2;
    return solution;
}
