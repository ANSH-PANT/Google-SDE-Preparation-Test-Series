/*
Time Complexity: O(n * log(sum - mx))
Space Complexity: O(n)
*/

class Solution {
public:
    int ispossible(vector<int>& nums, int k, int ans) {
        int n = nums.size();
        int sum = 0;
        int req = 1;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] > ans) {
                req++;
                sum = nums[i];
            } 
            else
                sum += nums[i];
        }
        return (req <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k)
            return -1;
        int sum = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mx = max(mx, nums[i]);
        }
        int low = mx, high = sum;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ispossible(nums, k, mid)) {
                res = mid;
                high = mid - 1;

            } 
            else
                low = mid + 1;
        }
        return res;
    }
};
