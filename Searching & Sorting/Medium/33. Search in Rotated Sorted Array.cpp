/*
Linear Search Approach
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};


/*
Binary Search Approach
Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int stop = nums.size() - 1;
        while (start <= stop) {
            int middle = start + (stop - start) / 2;
            if (target == nums[middle]) {
                return middle;
            }
            if (nums[start] <= nums[middle]) {
                if (nums[start] <= target && target <= nums[middle]) {
                    stop = middle - 1;
                } 
                else {
                    start = middle + 1;
                }
            } 
            else {
                if (nums[middle] <= target && target <= nums[stop]) {
                    start = middle + 1;
                } 
                else {
                    stop = middle - 1;
                }
            }
        }
        return -1;
    }
};
