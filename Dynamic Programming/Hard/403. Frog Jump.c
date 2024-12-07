/*
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

bool solve(int* stones, int i, int lastjump, int** dp, int stonesSize) {
    if (dp[i][lastjump] != -1) {
        return dp[i][lastjump];
    }
    for (int j = i + 1; j < stonesSize; j++) {
        int jump = stones[j] - stones[i];
        if (jump < lastjump - 1) {
            continue;
        }
        if (jump > lastjump + 1) {
            return dp[i][lastjump] = 0;
        }
        if (solve(stones, j, jump, dp, stonesSize)) {
            return dp[i][lastjump] = 1;
        }
    }
    return dp[i][lastjump] = (i == stonesSize - 1);
}

bool canCross(int* stones, int stonesSize) {
    int** dp = (int**)malloc((stonesSize + 1) * sizeof(int*));
    for (int i = 0; i < stonesSize + 1; i++) {
        dp[i] = (int*)malloc((stonesSize + 1) * sizeof(int));
        for (int j = 0; j < stonesSize + 1; j++) {
            dp[i][j] = -1;
        }
    }
    bool result = solve(stones, 0, 0, dp, stonesSize);
    for (int i = 0; i < stonesSize + 1; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}
