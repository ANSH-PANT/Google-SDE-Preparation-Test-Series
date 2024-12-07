/*
Time Complexity: O(rows×cols)
Space Complexity: O(rows×cols)
*/

class NumMatrix {
    vector<int> sums;
    int cols;
    int rows;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        sums.reserve(rows * cols);
        int linesum = 0;
        for (int r = 0; r < rows; ++r) {
            auto& row = matrix[r];
            linesum = 0;
            for (int c = 0; c < cols; ++c) {
                linesum += row[c];
                int indx = r * cols + c;
                sums[indx] = linesum;
                sums[indx] += ((r == 0) ? 0 : sums[(r - 1) * cols + c]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = sums[row2 * cols + col2];
        result -= (col1 > 0) ? sums[row2 * cols + (col1 - 1)] : 0;
        result -= (row1 > 0) ? sums[(row1 - 1) * cols + col2] : 0;
        result += (row1 > 0 && col1 > 0) ? sums[(row1 - 1) * cols + col1 - 1] : 0;
        return result;
    }
};
