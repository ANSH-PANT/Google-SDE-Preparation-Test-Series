/*
Time Complexity: O(nodes)
Space Complexity: O(height)
*/

class Solution {
public:
    int depth(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        }
        int left = max(0, depth(root->left, maxi));
        int right = max(0, depth(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int maxi = INT_MIN;
        depth(root, maxi);
        return maxi;
    }
};
