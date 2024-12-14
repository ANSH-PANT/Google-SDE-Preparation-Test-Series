/*
Time Complexity: O(C(n, k) * k)
Space Complexity: O(C(n, k) + k)
*/

class Solution {
private:
    void traverse(int n, int k, int i, vector<int>& comb, vector<vector<int>>& all) {
        if (k == 0)
            all.push_back(comb);
        else if (i == n + 1) {
        } 
        else {
            for (int j = i; j <= n; j++) {
                comb.push_back(j);
                traverse(n, k - 1, j + 1, comb, all);
                comb.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> all;
        vector<int> comb;
        int i = 1;
        traverse(n, k, i, comb, all);
        return all;
    }
};
