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

// code 2

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else
                nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }
};
