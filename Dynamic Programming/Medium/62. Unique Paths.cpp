/*
Time complexity: O(2^(m + n))
Space complexity: O(m + n)
*/

class Solution {
private:
    int f1(int i, int j, const int m, const int n) {
        if(i == m - 1 && j == n - 1) {
            return 1;
        } 
        else {
            int allPaths = 0;
            if(j+1 <= n-1) {
                allPaths += f1(i, j+1, m, n);
            }
            if(i+1 <= m-1) {
                allPaths += f1(i+1, j, m, n);
            }
            return allPaths;
        }
    }

public:
    int uniquePaths(int m, int n) {
        return f1(0, 0, m, n);
    }
};

/*
Time complexity: O(m * n)
Space complexity: O(m * n)
*/

class Solution {
    vector<vector<int>> tbl;

private:
    int f1(int i, int j, const int m, const int n) {
        if(tbl[i][j] == INT_MIN) { 
            if(i == m - 1 && j == n - 1) {
                return tbl[i][j] = 1;
            } 
            else {
                int allPaths = 0;
                if(j+1 <= n-1) {
                    allPaths += f1(i, j+1, m, n);
                }
                if(i+1 <= m-1) {
                    allPaths += f1(i+1, j, m, n);
                }
                return tbl[i][j] = allPaths;
            }
        }
        return tbl[i][j];
    }

public:
    int uniquePaths(int m, int n) {
        tbl.clear();
        tbl.resize(m, vector<int>(n, INT_MIN));
        return f1(0, 0, m, n);
    }
};

/*
Time complexity: O(min(m, n))
Space complexity: O(1)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int R = min(m - 1, n - 1);
        double ans = 1;
        for(int i = 1; i <= R; ++i)
            ans = ans * (N--) / i;
        return (int)ans;    
    }   
};
