/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> fm;
        int ps = 0;
        fm[ps] = 1;
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            ps += nums[j];
            count += fm[ps - k];
            fm[ps]++;
        }
        return count;
    }
};
