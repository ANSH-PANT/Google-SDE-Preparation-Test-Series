/*
Time complexity: O(n log(max - min) * log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int h = matrix[n - 1][n - 1];
        int mid;
        int count;
        while (l < h) {
            count = 0;
            mid = l + (h - l) / 2;
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < k) {
                l = mid + 1;
            } 
            else {
                h = mid;
            }
        }
        return l;
    }
};
