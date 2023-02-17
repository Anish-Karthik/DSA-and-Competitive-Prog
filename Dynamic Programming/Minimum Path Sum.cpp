class Solution {
    // recursion
    int r(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j <0 ) return 1e9;
        if(i == 0 && j == 0) return grid[0][0];

        int up = r(i-1, j, grid);
        int left = r(i, j-1, grid);
        
        return grid[i][j] +  min(up, left);
    }
    // memoization
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i<0 || j <0 ) return 1e9;
        if(i == 0 && j == 0) return grid[0][0];

        if(dp[i][j] != -1) return dp[i][j];
        int up =  f(i-1,j, grid, dp);
        int left =  f(i,j-1, grid, dp);
        
        return dp[i][j] =  grid[i][j] +  min(up, left);
    }
    // tabulation
    int t(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if( i==0 && j ==0) {
                    dp[i][j] = grid[0][0];
                    continue;
                }
                int up = 1e9, left = 1e9;
                if(!(i-1<0)) up = dp[i-1][j];
                if(!(j-1<0)) left = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(up, left);
            }
        } 
        return dp[n-1][m-1];
    }
    // space optimization
    int s(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
        vector<int> prev(m, 0);
        for(int i = 0; i<n; i++) {
            vector<int> cur(m, 0);
            for(int j = 0; j<m; j++) {
                if( i==0 && j ==0) {
                    cur[j] = grid[0][0];
                    continue;
                }
                int up = 1e9, left = 1e9;
                if(!(i-1<0)) up = prev[j];
                if(!(j-1<0)) left = cur[j-1];
                cur[j] = grid[i][j] + min(up, left);
            }
            prev = cur;
        } 
        return prev[m-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return f(n-1,m-1, grid,dp);
        return s(grid);
    }
};
