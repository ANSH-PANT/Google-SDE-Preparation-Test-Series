/*
Time Complexity: O(nodes)
Space Complexity: O(height)
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        auto invertedLeft = invertTree(root->left);
        auto invertedRight = invertTree(root->right);
        root->right = invertedLeft;
        root->left = invertedRight;
        return root;
    }
};
