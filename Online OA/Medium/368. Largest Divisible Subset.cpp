/*
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> dp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j].size() > dp[i].size()) {
                    dp[i] = dp[j];
                }
            }
            dp[i].push_back(nums[i]);
            if (ans.size() < dp[i].size())
                ans = dp[i];
        }
        return ans;
    }
};
