/*
Bruteforce Approach:
Time Complexity: O(n^2 log n)
Space Complexity: O(n^2)
*/

class Solution {
private:
    int f1(const vector<int>& nums, map<pair<int, int>, int>& f2tbl) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        return max(f2(nums, 0, nums.size() - 2, f2tbl), f2(nums, 1, nums.size() - 1, f2tbl));
    }

    int f2(const vector<int>& nums, int i, int j, map<pair<int, int>, int>& f2tbl) {
        pair<int, int> key = {i, j};
        if (f2tbl.find(key) != f2tbl.end())
            return f2tbl[key];
        int n = j - i + 1;
        if (n == 0)
            return f2tbl[key] = 0;
        if (n == 1)
            return f2tbl[key] = nums[i];
        return f2tbl[key] = max(f2(nums, i, j - 1, f2tbl), f2(nums, i, j - 2, f2tbl) + nums[j]);
    }

public:
    int rob(vector<int>& nums) {
        map<pair<int, int>, int> f2tbl;
        return f1(nums, f2tbl);
    }
};

/*
Optimised Approach:
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
private:
    int f1(const vector<int>& nums, vector<vector<int>>& f2tbl) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        return max(f2(nums, 0, nums.size() - 2, f2tbl),
                   f2(nums, 1, nums.size() - 1, f2tbl));
    }
    int f2(const vector<int>& nums, int i, int j, vector<vector<int>>& f2tbl) {
        int n = j - i + 1;
        if (n == 0)
            return 0;
        if (f2tbl[i][j] != -1)
            return f2tbl[i][j];
        if (n == 1)
            return f2tbl[i][j] = nums[i];
        return f2tbl[i][j] = max(f2(nums, i, j - 1, f2tbl),
                                 f2(nums, i, j - 2, f2tbl) + nums[j]);
    }

public:
    int rob(vector<int>& nums) {
        vector<vector<int>> f2tbl(2, vector<int>(nums.size(), -1));
        return f1(nums, f2tbl);
    }
};
