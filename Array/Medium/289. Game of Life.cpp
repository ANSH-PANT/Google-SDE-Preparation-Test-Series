/*
Time Complexity: O(m * n)
Space Complexity: O(1)
*/  

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                for (int I = max(i - 1, 0); I < min(i + 2, m); ++I)
                    for (int J = max(j - 1, 0); J < min(j + 2, n); ++J)
                        count += board[I][J] & 1;
                if (count == 3 || count - board[i][j] == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};
