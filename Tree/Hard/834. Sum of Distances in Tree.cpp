/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    struct TreeNode {
        int val;
        vector<TreeNode*> children;
        TreeNode(int v) : val(v) {}
    };

private:
    void f1(TreeNode* root, int nodesCountFromSky, int distSumFromSky,
            unordered_map<TreeNode*, int>& nodesCount,
            unordered_map<TreeNode*, int>& distSum, vector<int>& answer) {
        if (!root)
            return;
        answer[root->val] = distSumFromSky + nodesCountFromSky;
        for (TreeNode* child : root->children) {
            answer[root->val] += distSum[child] + nodesCount[child];
        }
        for (TreeNode* child : root->children) {
            f1(child, answer.size() - nodesCount[child],
               answer[root->val] - (distSum[child] + nodesCount[child]),
               nodesCount, distSum, answer);
        }
    }
    void preprocess(TreeNode* root, unordered_map<TreeNode*, int>& nodesCount, unordered_map<TreeNode*, int>& distSum) {
        if (!root)
            return;
        int count = 1, dist = 0;
        for (TreeNode* child : root->children) {
            preprocess(child, nodesCount, distSum);
            count += nodesCount[child];
            dist += distSum[child] + nodesCount[child];
        }
        nodesCount[root] = count;
        distSum[root] = dist;
    }
    void dfs(TreeNode* root, TreeNode* parent, const vector<vector<int>>& g) {
        for (int v : g[root->val]) {
            if (!parent || parent->val != v) {
                TreeNode* child = new TreeNode(v);
                root->children.push_back(child);
                dfs(child, root, g);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        TreeNode* root = new TreeNode(0);
        dfs(root, nullptr, g);
        vector<int> answer(n);
        unordered_map<TreeNode*, int> nodesCount;
        unordered_map<TreeNode*, int> distSum;
        preprocess(root, nodesCount, distSum);
        f1(root, 0, 0, nodesCount, distSum, answer);
        return answer;
    }
};
