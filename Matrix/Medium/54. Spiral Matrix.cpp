/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size(), col = matrix[0].size(), count = 0,
            total = row * col, startingRow = 0, startingCol = 0,
            endingRow = row - 1, endingCol = col - 1;
        while (count < total) {
            for (int index = startingCol; count < total && index <= endingCol;
                 index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            for (int index = startingRow; count < total && index <= endingRow;
                 index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            for (int index = endingCol; count < total && index >= startingCol;
                 index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            for (int index = endingRow; count < total && index >= startingRow;
                 index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};
