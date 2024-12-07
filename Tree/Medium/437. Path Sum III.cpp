/*
Time Complexity: O(n²)
Space Complexity: O(n)
*/

class Solution {
private:
    void backtrack(TreeNode* root, vector<int> path, int& pathsCount, int targetSum) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        long long sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == targetSum)
                pathsCount++;
        }
        backtrack(root->left, path, pathsCount, targetSum);
        backtrack(root->right, path, pathsCount, targetSum);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        int pathsCount = 0;
        backtrack(root, {}, pathsCount, targetSum);
        return pathsCount;
    }
};

/*
Time Complexity: O(n²)
Space Complexity: O(h)
*/

class Solution {
private:
    int pathSumWithRoot(TreeNode* root, long long targetSum) {
        if(!root) 
            return 0;
        return (root->val == targetSum) + pathSumWithRoot(root->left, targetSum - root->val) + pathSumWithRoot(root->right, targetSum - root->val);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) 
            return 0;
        return pathSumWithRoot(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
