/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int f = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            f += i * nums[i];
        }
        int globalSum = f;
        for (int i = nums.size() - 1; i > 0; i--) {
            f = f + sum - nums.size() * nums[i];
            globalSum = max(f, globalSum);
        }
        return globalSum;
    }
};
