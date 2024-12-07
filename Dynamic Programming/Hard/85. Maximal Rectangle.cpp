/*
Bruteforcce Approach:
Time Complexity: O(m * n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i1 = 0; i1 < m; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                int ans2 = 0;
                int i2 = i1;
                int j2bound = n;
                while (i2 < m && matrix[i2][j1] == '1') {
                    int j2 = j1;
                    while (j2 < j2bound && matrix[i2][j2] == '1') {
                        j2++;
                    }
                    i2++;
                    ans2 = max(ans2, (i2 - i1) * (j2 - j1));
                    j2bound = j2;
                }
                ans = max(ans, ans2);
            }
        }
        return ans;
    }
};

/*
Optimised Approach:
Time Complexity: O(m * n * log n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> zeros(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0')
                    zeros[i].push_back(j);
            }
            zeros[i].push_back(n);
        }
        int ans = 0;
        for (int i1 = 0; i1 < m; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                int ans2 = 0;
                int i2 = i1;
                int j2bound = n;
                while (i2 < m && j2bound > j1 && matrix[i2][j1] == '1') {
                    int j2 = *lower_bound(zeros[i2].begin(), zeros[i2].end(), j1);
                    i2++;
                    j2bound = min(j2bound, j2);
                    ans2 = max(ans2, (i2 - i1) * (j2bound - j1));
                }
                ans = max(ans, ans2);
            }
        }
        return ans;
    }
};
