/*
Time Complexity: O(n×m)
Space Complexity: O(n×m)
*/

class Solution {
    const vector<int> delta = {-1, 0, 1, 0};
    unordered_map<int, int> low, tin;
    int timer = 0;
    bool articulation_point = false;

    void dfs(unordered_map<int, vector<int>>& adj, int u, int par) {
        low[u] = tin[u] = ++timer;
        int child_count = 0;
        for (int v : adj[u])
            if (v != par) {
                if (low.count(v)) {
                    low[u] = min(low[u], tin[v]);
                } 
                else {
                    child_count++;
                    dfs(adj, v, u);
                    if (low[v] >= tin[u] && par != -1) {
                        articulation_point = true;
                    }
                    low[u] = min(low[u], low[v]);
                }
            }
        if (par == -1 && child_count > 1)
            articulation_point = true;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        const int V = n * m;
        unordered_map<int, vector<int>> adj;
        int vertex_count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j]) {
                    int id = i * m + j;
                    adj[id] = {};
                    for (int k = 0; k < 4; k++) {
                        int r = i + delta[k], c = j + delta[(k + 1) % 4];
                        if (r < n && c < m && r >= 0 && c >= 0 && grid[r][c]) {
                            int id_adj = r * m + c;
                            adj[id].push_back(id_adj);
                        }
                    }
                }
        if (adj.size() <= 1)
            return adj.size();
        bool multiple_dfs = 0;
        for (auto& it : adj)
            if (!low.count(it.first)) {
                if (multiple_dfs)
                    return 0;
                dfs(adj, it.first, -1);
                multiple_dfs = 1;
            }
        if (articulation_point)
            return 1;
        return 2;
    }
};
