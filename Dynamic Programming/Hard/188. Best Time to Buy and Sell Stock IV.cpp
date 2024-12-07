/*
Time Complexity: O(n * k)
Space Complexity: O(k)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), K = k;
        vector<vector<int>> f1(2, vector<int>(k + 1, 0)), f2(2, vector<int>(k + 1, prices.back()));
        for (int i = n - 2; i >= 0; i--) {
            for (int k = 0; k <= K; k++) {
                f1[i % 2][k] = f1[(i + 1) % 2][k];
                if (k > 0)
                    f1[i % 2][k] = max(f1[i % 2][k], f2[(i + 1) % 2][k] - prices[i]);
                if (k > 0)
                    f2[i % 2][k] = max(f2[(i + 1) % 2][k], f1[(i + 1) % 2][k - 1] + prices[i]);
            }
        }
        return f1[0][K];
    }
};
