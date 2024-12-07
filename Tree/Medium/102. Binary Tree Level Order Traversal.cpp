/*
Bruteforce Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> v;
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

/*
Recursive Approach:
Time Complexity: O(nodes)
Space Complexity: O(height)
*/

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void atKdist(TreeNode* root, int k, vector<int>& res) {
        if (root == NULL)
            return;
        if (k == 0)
            res.push_back(root->val);
        else {
            atKdist(root->left, k - 1, res);
            atKdist(root->right, k - 1, res);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans;
        vector<int> res;
        for (int i = 0; i < h; i++) {
            atKdist(root, i, res);
            ans.push_back(res);
            res.clear();
        }
        return ans;
    }
};
