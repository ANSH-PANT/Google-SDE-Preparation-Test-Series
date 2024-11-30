https://leetcode.com/problems/two-sum/

/*
Bruteforce Approach:
Time Complexity: O(n²)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mp.find(moreNeeded) != mp.end()) {
                return {mp[moreNeeded], i};
            }
            mp[num] = i;
        }
        return {-1, -1};
    }
};
