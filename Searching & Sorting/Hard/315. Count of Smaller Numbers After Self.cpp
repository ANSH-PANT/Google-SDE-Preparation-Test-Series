/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    class SegNode {
    public:
        int sum, i, j;
        SegNode* left;
        SegNode* right;
        SegNode(int i1, int j1)
            : sum(0), i(i1), j(j1), left(nullptr), right(nullptr) {}
    };
    SegNode* root;
    int LEFT = -10001, RIGHT = 10001;

private:
    int sumRange(SegNode* node, int i, int j) {
        if (node->i == i && node->j == j)
            return node->sum;
        int sum = 0;
        int mid = node->i + (node->j - node->i) / 2;
        if (i <= mid && node->left)
            sum += sumRange(node->left, i, min(j, mid));
        if (j >= mid + 1 && node->right)
            sum += sumRange(node->right, max(i, mid + 1), j);
        return sum;
    }
    void insert(SegNode* node, int val) {
        node->sum++;
        if (node->i == node->j)
            return;
        int mid = node->i + (node->j - node->i) / 2;
        if (val <= mid) {
            if (node->left == nullptr)
                node->left = new SegNode(node->i, mid);
            insert(node->left, val);
        } 
        else {
            if (node->right == nullptr)
                node->right = new SegNode(mid + 1, node->j);
            insert(node->right, val);
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        root = new SegNode(LEFT, RIGHT);
        vector<int> counts(n);
        for (int i = n - 1; i >= 0; i--) {
            counts[i] = sumRange(root, LEFT, nums[i] - 1);
            insert(root, nums[i]);
        }
        return counts;
    }
};
