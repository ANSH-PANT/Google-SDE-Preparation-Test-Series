/*
Time Complexity: O(n)
Space Complexity: O(1)
*/    
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1])
                nums[j++] = nums[i];
        }
        return j;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/    
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = unique(nums.begin(), nums.end()) - nums.begin();
        return j;
    }
};
