/*
Time complexity: O(2^n)
Space complexity: O(n)
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/*
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        int sum = 0, a = 0, b = 1;
        for(int i = 1; i <= n; i++) {
        sum = a + b;
        a = b;
        b = sum;    
        }
        return b;    
    }   
};
