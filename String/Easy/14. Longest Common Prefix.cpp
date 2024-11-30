/*
Time Complexity: O(m * n), where m is the length of the shortest string, and n is the number of strings.
Space Complexity: O(m)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int i = 0;
        for (auto it : strs[0]) {
            for (auto jt : strs) {
                if (jt[i] != it) {
                    return s;
                }
            }
            s = s + it;
            i++;
        }
        return s;
    }
};
