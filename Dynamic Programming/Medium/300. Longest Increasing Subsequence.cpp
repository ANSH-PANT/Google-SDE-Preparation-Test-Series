/*
Bruteforce Approach:
Time Complexity: O(2^n)
Space Complexity: O(n)
*/

class Solution {
private:
    int f1(int i, int p, vector<int>& nums) {
        if(i == nums.size()) 
          return 0;
        int res = f1(i+1, p, nums);
        if(p == -1 || nums[i] > nums[p]) {
            res = max(res, 1 + f1(i+1, i, nums));
        }
        return res;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return f1(0, -1, nums);
    }
};

/*
Better Approach:
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
private:
    int f1(int i, int p, vector<int>& nums) {
        if(i == nums.size())
          return 0;
        int res = f1(i+1, p, nums);
        if(p == -1 || nums[i] > nums[p]) {
            res = max(res, 1 + f1(i+1, i, nums));
        }
        return res;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return f1(0, -1, nums);
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

/*
Optimised Approach:
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> seq = {nums[0]};
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > seq.back()) 
              seq.push_back(nums[i]);
            else {
                int j = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[j] = nums[i];
            }
        }
        return seq.size();
    }
};
