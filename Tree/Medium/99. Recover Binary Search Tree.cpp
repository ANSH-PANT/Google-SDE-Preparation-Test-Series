/*
Time Complexity: O(nodes)
Space Complexity: O(height)
*/

class Solution {
private:
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        if (prev && prev->val > root->val) {
            if (!first)
                first = prev;
            middle = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* prev = nullptr;
    void recoverTree(TreeNode* root) {
        if (root == nullptr)
            return;
        prev = nullptr;
        inorder(root);
        if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};
