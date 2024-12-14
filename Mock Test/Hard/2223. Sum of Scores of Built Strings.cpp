/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    int n;
    vector<int> solve(string s) {
        vector<int> vec(n);
        int i = 0, j = 0;
        vec[0] = n;
        for (int k = 1; k < n; ++k) {
            if (k <= j) {
                vec[k] = min(j - k + 1, vec[k - i]);
            }
            while (k + vec[k] < n && s[vec[k]] == s[k + vec[k]]) {
                vec[k]++;
            }
            if (k + vec[k] - 1 > j) {
                i = k;
                j = k + vec[k] - 1;
            }
        }
        return vec;
    }

public:
    long long sumScores(string s) {
        n = s.size();
        vector<int> v = solve(s);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += v[i];
        }
        return ans;
    }
};
