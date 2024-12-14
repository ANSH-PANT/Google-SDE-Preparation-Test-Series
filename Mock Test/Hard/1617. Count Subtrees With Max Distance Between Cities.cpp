/*
Time Complexity: O(2^n * n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>(n, 999));
        for (auto& e : edges) {
            int i = e[0] - 1;
            int j = e[1] - 1;
            g[i][j] = g[j][i] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        vector<int> ans(n - 1, 0);
        for (int s = 0; s < (1 << n); s++) {
            int k = __builtin_popcount(s);
            int e = 0;
            int d = 0;
            for (int i = 0; i < n; i++)
                if (s & (1 << i)) {
                    for (int j = i + 1; j < n; j++)
                        if (s & (1 << j)) {
                            e += g[i][j] == 1;
                            d = max(d, g[i][j]);
                        }
                }
            if (e == k - 1 && d > 0) {
                ans[d - 1]++;
            }
        }
        return ans;
    }
};
