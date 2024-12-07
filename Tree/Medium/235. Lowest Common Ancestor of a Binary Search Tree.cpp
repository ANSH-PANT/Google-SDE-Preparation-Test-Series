/*
Time Complexity: O(nodes)
Space Complexity: O(height)
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == root || q == root) {
            return root;
        }
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else {
            return root;
        }
    }
};
