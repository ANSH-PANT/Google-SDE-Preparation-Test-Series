/*
Bruteforce Approach:
Time Complexity: O(2^(m+n))
Space Complexity: O(m+n)
*/

class Solution {
    int m, n;
private:
    int f1(vector<vector<int>>& grid, int i, int j) {
        if (i == m-1 && j == n-1) {
            return grid[m-1][n-1];
        } 
        else {
            int minSum = INT_MAX;
            if (j+1 <= n-1) 
              minSum = min(minSum, grid[i][j] + f1(grid, i, j+1));
            if (i+1 <= m-1) 
              minSum = min(minSum, grid[i][j] + f1(grid, i+1, j));
            return minSum;
        }
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        return f1(grid, 0, 0);
    }
};

/*
Better Approach:
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
    int m, n;
private:
    int f1(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& f1tbl) {
        if(f1tbl[i][j] != INT_MIN) 
          return f1tbl[i][j];
        if(i == m-1 && j == n-1) {
            return f1tbl[i][j] = grid[m-1][n-1];
        } 
        else {
            f1tbl[i][j] = INT_MAX;
            if(j+1 <= n-1) 
              f1tbl[i][j] = min(f1tbl[i][j], grid[i][j] + f1(grid, i, j+1, f1tbl));
            if(i+1 <= m-1) 
              f1tbl[i][j] = min(f1tbl[i][j], grid[i][j] + f1(grid, i+1, j, f1tbl));
            return f1tbl[i][j];
        }
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> f1tbl(m, vector<int>(n, INT_MIN));
        return f1(grid, 0, 0, f1tbl);
    }
};

/*
Optimised Approach:
Time Complexity: O(m * n)
Space Complexity: O(n)
*/

class Solution {
    int m, n;

public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> f1tbl(n, INT_MAX);
        f1tbl[0] = grid[0][0];
        for(int j = 1; j < n; j++) {
            f1tbl[j] = grid[0][j] + f1tbl[j-1];
        }
        
        for(int i = 1; i < m; i++) {
            f1tbl[0] += grid[i][0];
            for(int j = 1; j < n; j++) {
                f1tbl[j] = grid[i][j] + min(f1tbl[j], f1tbl[j-1]);
            }
        }
        return f1tbl[n-1];
    }
};
