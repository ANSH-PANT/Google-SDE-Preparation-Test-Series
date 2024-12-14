/*
Bruteforce Approach:
Time Complexity:
  update(): O(n)
  sumRange(): O(1)
Space Complexity: O(n)
*/

class NumArray {
    vector<int> ps;

public:
    NumArray(vector<int>& nums) {
        ps.resize(nums.size());
        ps[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ps[i] = ps[i - 1] + nums[i];
        }
    }

    void update(int index, int val) {
        int numsOfi = (index == 0) ? ps[0] : (ps[index] - ps[index - 1]);
        int diff = val - numsOfi;
        for (int i = index; i < ps.size(); i++) {
            ps[i] += diff;
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return ps[right];
        return ps[right] - ps[left - 1];
    }
};

/*
Time Complexity:
  update(): O(log n)
  sumRange(): O(log n)
Space Complexity: O(n)  
*/

class NumArray {
    class SegNode {
    public:
        int sum, i, j;
        SegNode* left;
        SegNode* right;
        SegNode(int i1, int j1)
            : sum(0), i(i1), j(j1), left(nullptr), right(nullptr) {}
    };
    SegNode* root;
    vector<int> nums;

private:
    SegNode* build(int i, int j, const vector<int>& nums) {
        auto node = new SegNode(i, j);
        if (i == j) {
            node->sum = nums[i];
        } 
        else {
            int mid = i + (j - i) / 2;
            node->left = build(i, mid, nums);
            node->right = build(mid + 1, j, nums);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    void update(SegNode* node, int index, int diff) {
        node->sum += diff;
        if (node->left == nullptr)
            return;
        int mid = node->i + (node->j - node->i) / 2;
        if (index <= mid)
            update(node->left, index, diff);
        else
            update(node->right, index, diff);
    }

    int sumRange(SegNode* node, int left, int right) {
        if (left == node->i && right == node->j)
            return node->sum;
        int mid = node->i + (node->j - node->i) / 2;
        int sum = 0;
        if (left <= mid)
            sum += sumRange(node->left, left, min(right, mid));
        if (right >= mid + 1)
            sum += sumRange(node->right, max(mid + 1, left), right);
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        root = build(0, nums.size() - 1, nums);
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        update(root, index, diff);
    }

    int sumRange(int left, int right) { 
      return sumRange(root, left, right); 
    }
};
