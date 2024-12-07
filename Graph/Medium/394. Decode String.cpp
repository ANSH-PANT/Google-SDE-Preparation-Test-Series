/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string decodeString(string s) { return f1(s, 0, s.size() - 1); }

private:
    string f1(string& s, int low, int high) {
        if (low > high)
            return "";
        if (!isdigit(s[low])) {
            string result;
            result.push_back(s[low]);
            result += f1(s, low + 1, high);
            return result;
        }
        int k = 0;
        while (s[low] != '[') {
            k = 10 * k + (s[low] - '0');
            low++;
        }
        int i = low + 1;
        int j = i;
        int pending = 0;
        while (pending > 0 || s[j + 1] != ']') {
            if (s[j + 1] == '[')
                pending++;
            else if (s[j + 1] == ']')
                pending--;
            j++;
        }
        auto s1 = f1(s, i, j);
        string result;
        while (k--) {
            result += s1;
        }
        result += f1(s, j + 2, high);
        return result;
    }
};
