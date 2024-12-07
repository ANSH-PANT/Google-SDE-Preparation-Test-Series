/*
Bruteforce Approach:
Time Complexity: O(2^(n))
Space Complexity: O(n)
*/

class Solution {
private:
    int f1(const string& s, int i) {
        if(i == s.size()) 
          return 1;
        int count = 0;
        if(s[i] >= '1' && s[i] <= '9') {
            count += f1(s, i+1);
        }
        if(i+1 < s.size()) {
            int val = 10 * (s[i] - '0') + (s[i+1] - '0');
            if(val >= 10 && val <= 26) {
                count += f1(s, i+2);
            }
        }
        return count;
    }

public:
    int numDecodings(string s) {
        return f1(s, 0);
    }
};

/*
Better Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
private:
    int f1(int i, string& s, vector<int>& tbl) {
        if(tbl[i] != INT_MIN) 
          return tbl[i];
        if(i == s.size()) 
          return tbl[i] = 1;
        if(i == s.size() - 1) {
            return tbl[i] = (s[i] >= '1' && s[i] <= '9');
        }
        tbl[i] = 0;
        if(s[i] >= '1' && s[i] <= '9') 
          tbl[i] += f1(i+1, s, tbl);
        int val = 10 * (s[i] - '0') + (s[i+1] - '0');
        if(val >= 10 && val <= 26) 
          tbl[i] += f1(i+2, s, tbl);
        return tbl[i];
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> tbl(n+1, INT_MIN);
        return f1(0, s, tbl);
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f1(3);
        f1[n % 3] = 1;
        for(int i = n-1; i >= 0; i--) {
            int count = 0;
            if(s[i] >= '1' && s[i] <= '9') {
                count += f1[(i+1)%3];
            }
            if(i+1 < s.size()) {
                int val = 10 * (s[i] - '0') + (s[i+1] - '0');
                if(val >= 10 && val <= 26) {
                    count += f1[(i+2)%3];
                }
            }
            f1[i%3] = count;
        }
        return f1[0];
    }
};
