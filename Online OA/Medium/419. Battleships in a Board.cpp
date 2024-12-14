/*
Time Complexity: O(m * n)
Space Complexity: O(1)
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if ('X' == board[i][j] && (!i || '.' == board[i - 1][j]) && (!j || '.' == board[i][j - 1]))
                    ans++;
        return ans;
    }
};
