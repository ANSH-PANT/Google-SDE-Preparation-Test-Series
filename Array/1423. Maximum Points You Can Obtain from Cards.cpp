/*
Time Complexity: O(k)
Space Complexity: O(1)
*/
class Solution {
    int n;

public:
    int maxScore(vector<int>& cardPoints, int k) {
        n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int maxSum = sum;
        for (int j = n - 1, i = k - 1; i >= 0; j--, i--) {
            sum += cardPoints[j] - cardPoints[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
