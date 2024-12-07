/*
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

class Solution {
    int n;
private:
    int f1(vector<int>& A, int i, int j, vector<vector<int>>& f1tbl) {
        if (f1tbl[i][j] != INT_MIN)
            return f1tbl[i][j];
        if (j - i + 1 == 0)
            return f1tbl[i][j] = 0;
        f1tbl[i][j] = 0;
        for (int k = i; k <= j; k++) {
            f1tbl[i][j] = max(f1tbl[i][j], A[i - 1] * A[k] * A[j + 1] + f1(A, i, k - 1, f1tbl) + f1(A, k + 1, j, f1tbl));
        }
        return f1tbl[i][j];
    }

public:
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        vector<int> A(n + 2);
        A[0] = A[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            A[i + 1] = nums[i];
        }
        vector<vector<int>> f1tbl(n + 2, vector<int>(n + 2, INT_MIN));
        return f1(A, 1, n, f1tbl);
    }
};
