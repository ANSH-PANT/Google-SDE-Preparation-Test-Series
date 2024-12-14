/*
Time Complexity: O(2^n * n)
Space Complexity: O(n)
*/

class Solution {
private:
    void traverse(const string& s, int i, <string>& par, vector<vector<string>>& all) {
        if (i == s.size()) {
            all.push_back(par);
        } 
        else {
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(s, i, j)) {
                    string str = s.substr(i, j - i + 1);
                    par.push_back(str);
                    traverse(s, j + 1, par, all);
                    par.pop_back();
                }
            }
        }
    }

    bool isPalindrome(const string& s, int i, int j) {
        if (i >= j)
            return true;
        return (s[i] == s[j]) && isPalindrome(s, i + 1, j - 1);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> all;
        vector<string> par;
        int i = 0;
        traverse(s, i, par, all);
        return all;
    }
};
