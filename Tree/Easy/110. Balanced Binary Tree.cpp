/*
Bruteforce Approach: 
Time Complexity: O(n²)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        traverse(root, balanced);
        return balanced;
    }
private:
    void traverse(TreeNode* root, bool& balanced) {
        if(root == nullptr) return;
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left - right) > 1) balanced = false;
        
        traverse(root->left, balanced);
        traverse(root->right, balanced);
    }
    
    int height(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        unordered_map<TreeNode*, int> htbl;
        traverse(root, balanced, htbl);
        return balanced;
    }
private:
    void traverse(TreeNode* root, bool& balanced, unordered_map<TreeNode*, int>& htbl) {
        if(root == nullptr) 
          return;
        int left = height(root->left, htbl);
        int right = height(root->right, htbl);
        if(abs(left - right) > 1) 
          balanced = false;
        traverse(root->left, balanced, htbl);
        traverse(root->right, balanced, htbl);
    }
    
    int height(TreeNode* root, unordered_map<TreeNode*, int>& htbl) {
        if(htbl.find(root) != htbl.end()) 
          return htbl[root];
        if(root == nullptr) 
          return htbl[root] = 0;
        return htbl[root] = 1 + max(height(root->left, htbl), height(root->right, htbl));
    }
};
