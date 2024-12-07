/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
private:
    void dfs(int x, int y, int m, int n, int prev, vector<vector<int>>& heights,
             vector<vector<int>>& state, int type) {
        if (x < 0 || x >= m || y < 0 || y >= n || heights[x][y] < prev ||
            (state[x][y] & type) != 0)
            return;
        state[x][y] |= type;
        dfs(x + 1, y, m, n, heights[x][y], heights, state, type);
        dfs(x - 1, y, m, n, heights[x][y], heights, state, type);
        dfs(x, y + 1, m, n, heights[x][y], heights, state, type);
        dfs(x, y - 1, m, n, heights[x][y], heights, state, type);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.front().size();
        vector<vector<int>> state(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(i, 0, m, n, 0, heights, state, 1);
            dfs(i, n - 1, m, n, 0, heights, state, 2);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, m, n, 0, heights, state, 1);
            dfs(m - 1, j, m, n, 0, heights, state, 2);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (state[i][j] == 3) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
