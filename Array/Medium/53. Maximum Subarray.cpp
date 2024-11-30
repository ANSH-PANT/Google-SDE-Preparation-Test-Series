/*
Bruteforce Approach:
Time Complexity: O(n^3)
Space Complexity: O(1)
*/ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxval = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int sum = 0;
                for(int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                maxval = max(maxval, sum);
            }
        }
        return maxval;
    }
};

/*
Bruteforce Approach:
Time Complexity: O(n²)
Space Complexity: O(1)
*/
    
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxval = INT_MIN;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                maxval = max(maxval, sum);
            }
        }
        return maxval;
    }
};

/*
Better Approach:
Time Complexity: O(n log n)
Space Complexity: O(log n)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return f1(0, n-1, nums);
    }
private:
    int f1(int i, int j, vector<int>& nums) {
        if(j == i) return nums[j];
        int mid = i + (j-i)/2;
        int ans = max(f1(i, mid, nums), f1(mid+1, j, nums));
        int suff = nums[mid];
        int maxsuff = suff;
        for(int k = mid-1; k >= i; k--) {
            suff += nums[k];
            maxsuff = max(maxsuff, suff);
        }
        int pref = nums[mid+1];
        int maxpref = pref;
        for(int k = mid+2; k <= j; k++) {
            pref += nums[k];
            maxpref = max(maxpref, pref);
        }
        
        return max(ans, maxsuff + maxpref);
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int f1 = nums[0], f2 = nums[0];
        for(int n = 2; n <= nums.size(); n++) {
            f2 = max( nums[n-1], nums[n-1] + f2);
            f1 = max( f1, f2 );
        }
        return f1;
    }
};

/*
Kadane's Algorithm:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int curr_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > curr_sum) {
                curr_sum = sum;
            }
            if (sum < 0)
                sum = 0;
        }
        return curr_sum;
    }
};
