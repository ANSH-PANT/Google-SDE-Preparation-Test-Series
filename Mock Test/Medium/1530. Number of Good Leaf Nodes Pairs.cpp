/*
Bruteforce Approach: 
Time Complexity: O(n×d^2)
Space Complexity: O(n)
*/

class Solution1 {
private:
    pair<int, unordered_map<int, int>> f1(TreeNode* root, int dist) {
        if (!root)
            return {0, {}};
        if (!root->left && !root->right) {
            return {0, {{0, 1}}};
        }
        auto left = f1(root->left, dist);
        auto right = f1(root->right, dist);
        int count = left.first + right.first;
        for (auto& keyval1 : left.second) {
            for (auto& keyval2 : right.second) {
                if (1 + keyval1.first + 1 + keyval2.first <= dist) {
                    count += keyval1.second * keyval2.second;
                }
            }
        }
        unordered_map<int, int> leaves;
        for (auto& keyval : left.second) {
            if (1 + keyval.first < dist)
                leaves[1 + keyval.first] += keyval.second;
        }
        for (auto& keyval : right.second) {
            if (1 + keyval.first < dist)
                leaves[1 + keyval.first] += keyval.second;
        }
        return {count, leaves};
    }

public:
    int countPairs(TreeNode* root, int distance) {
        return f1(root, distance).first;
    }
};

/*
Better Approach:
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
private:
    int dfs(TreeNode* node, unordered_set<TreeNode*>& visited, int distance, unordered_set<TreeNode*>& leaves, unordered_map<TreeNode*, TreeNode*>& parent) {
        visited.insert(node);
        int count = 0;
        if (leaves.find(node) != leaves.end()) {
            count++;
        }
        if (0 == distance)
            return count;
        if (node->left && visited.find(node->left) == visited.end())
            count += dfs(node->left, visited, distance - 1, leaves, parent);
        if (node->right && visited.find(node->right) == visited.end())
            count += dfs(node->right, visited, distance - 1, leaves, parent);
        if (parent[node] != nullptr && visited.find(parent[node]) == visited.end())
            count += dfs(parent[node], visited, distance - 1, leaves, parent);
        return count;
    }

    void populate(TreeNode* root, unordered_set<TreeNode*>& leaves, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            leaves.insert(root);
        } 
        else {
            if (root->left) {
                parent[root->left] = root;
                populate(root->left, leaves, parent);
            }
            if (root->right) {
                parent[root->right] = root;
                populate(root->right, leaves, parent);
            }
        }
    }

public:
    int countPairs(TreeNode* root, int distance) {
        unordered_set<TreeNode*> leaves;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        populate(root, leaves, parent);
        int count = 0;
        for (TreeNode* leaf : leaves) {
            unordered_set<TreeNode*> visited;
            count += dfs(leaf, visited, distance, leaves, parent);
        }
        return (count - leaves.size()) / 2;
    }
};


/*
Optimised Approach:
Time Complexity: O(n×logn)
Space Complexity: O(n) 
*/

class Solution {
public:
    int ans = 0;
    vector<int> f(TreeNode* curr, int dis) {
        if (curr == nullptr) {
            return {};
        }
        if (!curr->left and !curr->right) {
            return {1};
        }
        auto left = f(curr->left, dis);
        auto right = f(curr->right, dis);
        if (!left.empty() and !right.empty()) {
            vector<int> ret;
            sort(right.begin(), right.end());
            for (auto iter : left) {
                int pos = upper_bound(right.begin(), right.end(), dis - iter) - right.begin();
                ans = ans + pos;
            }
        }
        for (int i = 0; i < right.size(); i++) {
            right[i]++;
        }
        for (auto iter : left) {
            right.push_back(iter + 1);
        }
        return right;
    }

    int countPairs(TreeNode* root, int distance) {
        f(root, distance);
        return ans;
    }
};
