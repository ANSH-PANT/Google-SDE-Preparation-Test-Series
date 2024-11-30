/*
Bruteforce Approach:
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) 
          return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
};

/*
Better Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) 
          return false;
        unordered_map<char, int> freqMap1;
        for(char c : s) 
          freqMap1[c]++;
        for(char c : t) {
            if(freqMap1[c] == 0) 
              return false;
            freqMap1[c]--;
        }
        return true;
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        vector<int> h(26);
        for(int i = 0; i < s.size(); i++) {
            h[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++) {
            int x = --h[t[i] - 'a'];
            if(x < 0) {
                return false;
            }
        }
        return true;
    }
};
