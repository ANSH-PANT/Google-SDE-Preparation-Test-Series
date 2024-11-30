/*
Bruteforce Approach:
Time Complexity: O(n log n) 
Space Complexity: O(n)
*/    

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

/*
Optimised Approach:
Time Complexity: O(n) 
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        nums.clear();
        for (auto i : mp) {
            if (i.second == 2)
                nums.push_back(i.first);
        }
        return nums;
    }
};
