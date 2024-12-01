/*
Time Complexity: O(n * m)
Space Complexity: O(n)
*/

class Solution {
private:
    bool isIndentical(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr || subRoot == nullptr)
            return false;
        if (root->val != subRoot->val)
            return false;
        return isIndentical(root->left, subRoot->left) && isIndentical(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        if (isIndentical(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
