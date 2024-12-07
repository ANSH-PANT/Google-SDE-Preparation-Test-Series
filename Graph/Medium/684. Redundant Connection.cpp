/*
Time Complexity: O(m * n)
Space Complexity: O(n + m)
*/

class Solution {
    unordered_set<int> seen;
    const int MAX_EDGE_VAL = 1000;

private:
    bool dfs(vector<int> graph[], int source, int target) {
        if (seen.find(source) == seen.end()) {
            seen.insert(source);
            if (source == target)
                return true;
            for (int nei : graph[source]) {
                if (dfs(graph, nei, target))
                    return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> graph[MAX_EDGE_VAL + 1];
        for (const auto& edge : edges) {
            seen.clear();
            if (!graph[edge[0]].empty() && !graph[edge[1]].empty() &&
                dfs(graph, edge[0], edge[1])) {
                return edge;
            }
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        throw runtime_error("No redundant connection found");
    }
};
