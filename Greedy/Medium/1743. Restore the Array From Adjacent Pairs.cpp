/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for (auto& p : adjacentPairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        vector<int> nums(1 + adjacentPairs.size());
        for (auto& keyval : graph) {
            if (keyval.second.size() == 1) {
                nums[0] = keyval.first;
                break;
            }
        }
        nums[1] = graph[nums[0]][0];
        for (int i = 2; i <= adjacentPairs.size(); i++) {
            if (graph[nums[i - 1]][0] != nums[i - 2])
                nums[i] = graph[nums[i - 1]][0];
            else
                nums[i] = graph[nums[i - 1]][1];
        }
        return nums;
    }
};
