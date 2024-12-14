/*
Time Complexity: O(n!)
Space Complexity: O(n^2)
*/

class Solution {
private:
    void search(int i, vector<string>& partialSolution, vector<vector<string>>& allSolutions) {
        int n = partialSolution.size();
        if (i == n) {
            allSolutions.push_back(partialSolution);
        } 
        else {
            for (int j = 0; j < n; j++) {
                bool legal = true;
                for (int k = 0; k < i; k++) {
                    if ((j - (i - k) >= 0 && partialSolution[k][j - (i - k)] == 'Q') || (partialSolution[k][j] == 'Q') || (j + (i - k) < n && partialSolution[k][j + (i - k)] == 'Q')) {
                        legal = false;
                        break;
                    }
                }
                if (legal) {
                    partialSolution[i][j] = 'Q';
                    search(i + 1, partialSolution, allSolutions);
                    partialSolution[i][j] = '.';
                } 
                else {
                }
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allSolutions;
        vector<string> partialSolution(n, string(n, '.'));
        search(0, partialSolution, allSolutions);
        return allSolutions;
    }
};
