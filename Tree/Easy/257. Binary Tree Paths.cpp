/*
Iterative (BFS) Approach
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<pair<TreeNode*, vector<int>>> que;
        que.push({root, {}});
        vector<vector<int>> allPaths;
        while (que.empty() == false) {
            auto [tree, path] = que.front();
            que.pop();
            path.push_back(tree->val);
            if (tree->left == nullptr && tree->right == nullptr) {
                allPaths.push_back(path);
            } else {
                if (tree->left)
                    que.push({tree->left, path});
                if (tree->right)
                    que.push({tree->right, path});
            }
        }
        vector<string> allPathsInStrings;
        for (vector<int> path : allPaths) {
            string pathStr = to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                pathStr += "->" + to_string(path[i]);
            }
            allPathsInStrings.push_back(pathStr);
        }
        return allPathsInStrings;
    }
};

/*
Recursive (DFS) Approach
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> allPaths = findAllPaths(root);
        vector<string> allPathsInStrings;
        for (vector<int> path : allPaths) {
            string pathStr = to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                pathStr += "->" + to_string(path[i]);
            }
            allPathsInStrings.push_back(pathStr);
        }
        return allPathsInStrings;
    }

private:
    vector<vector<int>> findAllPaths(TreeNode* root) {
        if (root == nullptr)
            return {};
        if (root->left == nullptr && root->right == nullptr) {
            return {{root->val}};
        }
        auto left = findAllPaths(root->left);
        for (vector<int>& path : left) {
            path.insert(path.begin(), root->val);
        }
        auto right = findAllPaths(root->right);
        for (vector<int>& path : right) {
            path.insert(path.begin(), root->val);
        }
        auto allPaths = left;
        allPaths.insert(allPaths.end(), right.begin(), right.end());
        return allPaths;
    }
};
