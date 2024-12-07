/*
Bruteforce Approach:
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 1;
            for (int j = i; j < n; j++) {
                sum *= nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product_1 = 1;
        int product_2 = 1;
        int new_product = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            product_1 *= nums[i];
            product_2 *= nums[nums.size() - 1 - i];
            new_product = max(new_product, max(product_1, product_2));
            if (product_1 == 0) {
                product_1 = 1;
            }
            if (product_2 == 0) {
                product_2 = 1;
            }
        }
        return new_product;
    }
};
