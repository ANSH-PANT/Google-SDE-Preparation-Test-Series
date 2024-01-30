class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int elem = nums[0];
        while(nums[elem] > 0) {
            nums[elem] = -nums[elem];
            elem = abs(nums[elem]);
        }
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }
        return elem;
    }
};
