/*
Bruteforce Approach:
Time Complexity: O(n * amount)
Space Complexity: O(n * amount)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> f1tbl(n + 1, vector<int>(amount + 1));
        f1tbl[n][0] = 0;
        for(int a = 1; a <= amount; a++) {
            f1tbl[n][a] = -1;
        }  
        for(int i = n-1; i >= 0; i--) {
            for(int a = 0; a <= amount; a++) {
                f1tbl[i][a] = f1tbl[i+1][a];
                if(coins[i] <= a) {
                    int with = f1tbl[i][a - coins[i]];
                    if(with != -1 && (f1tbl[i][a] == -1 || with + 1 < f1tbl[i][a])) {
                        f1tbl[i][a] = with + 1;
                    }
                }
            }
        }
        return f1tbl[0][amount];
    }
};

/*
Optimised Approach:
Time Complexity: O(n * amount)
Space Complexity: O(2 * amount)
*/

class Solution {
    int minCoins;

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> tbl(2, vector<int>(1 + amount, -1));
        tbl[n % 2][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int a = 0; a <= amount; a++) {
                tbl[i % 2][a] = tbl[(i + 1) % 2][a];
                if (a >= coins[i]) {
                    int with = tbl[i % 2][a - coins[i]];
                    if (with != -1 &&
                        (tbl[i % 2][a] == -1 || with + 1 < tbl[i % 2][a])) {
                        tbl[i % 2][a] = with + 1;
                    }
                }
            }
        }
        return tbl[0][amount];
    }
};
