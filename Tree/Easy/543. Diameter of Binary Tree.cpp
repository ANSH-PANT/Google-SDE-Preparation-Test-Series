/*
Bruteforce Approach:
Time Complexity: O(n²)
Space Complexity: O(h)
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) 
          return 0;
        int s1 = diameterOfBinaryTree(root->left);
        int s2 = diameterOfBinaryTree(root->right);
        int s3 = height(root->left) + height(root->right);
        return max(s1, max(s2, s3));
    }
private:
    int height(TreeNode* root) {
        if (root == nullptr) 
          return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};

/*
Better Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> htbl;
        return f1(root, htbl);
    }
private:
    int f1(TreeNode* root, unordered_map<TreeNode*, int>& htbl) {
        if (root == nullptr) 
          return 0;
        int s1 = f1(root->left, htbl);
        int s2 = f1(root->right, htbl);
        int s3 = height(root->left, htbl) + height(root->right, htbl);
        return max(s1, max(s2, s3));
    }
    int height(TreeNode* root, unordered_map<TreeNode*, int>& htbl) {
        if (htbl.find(root) != htbl.end()) 
          return htbl[root];
        if (root == nullptr) 
          return htbl[root] = 0;
        return htbl[root] = 1 + max(height(root->left, htbl), height(root->right, htbl));
    }
};

/*
Optimized Approach:
Time Complexity: O(n)
Space Complexity: O(h)
*/

class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0; 
        }
        maxDepth(root);
        return ans;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0; 
        }
        int left = maxDepth(root->left);               
        int right = maxDepth(root->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
};
