/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> count(m, vector<int>(n, 0));
        for (int i1 = 0; i1 < m; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                if (matrix[i1][j1] == 0)
                    continue;
                count[i1][j1] = 1;
                int i2 = i1 - 1, j2 = j1 - 1;
                while (i2 >= 0 && j2 >= 0 && matrix[i2][j1] == 1 &&
                       matrix[i1][j2] == 1 &&
                       count[i1 - 1][j1 - 1] >= (i1 - i2)) {
                    count[i1][j1]++;
                    i2--;
                    j2--;
                }
            }
        }
        int output = 0;
        for (int i1 = 0; i1 < m; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                output += count[i1][j1];
            }
        }
        return output;
    }
};
