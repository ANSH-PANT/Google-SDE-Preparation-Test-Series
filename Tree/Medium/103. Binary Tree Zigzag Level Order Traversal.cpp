/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 1;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (flag == 0) {
                reverse(temp.begin(), temp.end());
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};
