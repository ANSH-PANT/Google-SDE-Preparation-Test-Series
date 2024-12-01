/*
Bruteforce Approach:
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }

    string processString(string str) {
        string result;
        for (char c : str) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else {
                result += c;
            }
        }
        return result;
    }
};

/*
Optimised Approach:
Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0, p = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                k--;
                k = max(0, k);
            } 
            else {
                s[k] = s[i];
                k++;
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                p--;
                p = max(0, p);
            } 
            else {
                t[p] = t[i];
                p++;
            }
        }
        if (k != p) 
          return false;
        else {
            for (int i = 0; i < k; i++) {
                if (s[i] != t[i]) 
                  return false;
            }
            return true;
        }
    }
};
