/*
Bruteforce Approach:
Time Complexity: O(2^n)
Space Complexity: O(n)
*/

class Solution {
private:
    void traverse(int i, string partial, vector<string>& all, string& s, unordered_set<string>& dict) {
        if(i == s.size()) 
          all.push_back(partial);
        else {
            for(int j = i; j < s.size(); j++) {
                string substr = s.substr(i, j-i+1);
                if(dict.find(substr) != dict.end()) {
                    string str;
                    if(partial.empty()) 
                        str = substr;
                    else str = partial + " " + substr;
                    traverse(j+1, str, all, s, dict);
                }
            }
        }
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> all;
        string partial;
        int i = 0;
        traverse(i, partial, all, s, dict);
        return (all.size() > 0);
    }
};

/*
Better Approach:
Time Complexity: O(n^3)
Space Complexity: O(n)
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> f1tbl(1 + s.size());
        for(int i = s.size(); i >= 0; i--) {
            if(i == s.size()) 
              f1tbl[i] = true;
            else {
                bool answer = false;
                for(int j = i; j < s.size(); j++) {
                    string substr = s.substr(i, j-i+1);
                    if(dict.find(substr) != dict.end()) {
                        if(f1tbl[j+1]) 
                            answer = true;
                    }
                }
                f1tbl[i] = answer;
            }
        }
        return f1tbl[0];
    }
};

/*
Optimised Approach:
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
private:
    bool f1(const string& s, int i, unordered_set<string>& dict,
            vector<int>& tbl) {
        if (tbl[i] != INT_MIN)
            return tbl[i];
        if (i == s.size())
            return tbl[i] = true;
        tbl[i] = false;
        for (int j = i; j < s.size(); j++) {
            string word = s.substr(i, j - i + 1);
            if (dict.find(word) != dict.end()) {
                if (f1(s, j + 1, dict, tbl)) {
                    tbl[i] = true;
                    break;
                }
            }
        }
        return tbl[i];
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> tbl(s.size() + 1, INT_MIN);
        return f1(s, 0, dict, tbl);
    }
};
