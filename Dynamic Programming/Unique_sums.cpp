class Solution {
vector<vector<int>> dp;
private:
    int r(int i, int j) {
        if( i == 0 && j == 0) return 1;
        if( i<0 or j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = r(i-1, j);
        int left = r(i, j-1);

        return dp[i][j] = up + left;
    } 
public:
    int uniquePaths(int m, int n) {
        // dp.resize(m, vector<int>(n, -1));
        vector<int> prev(n,0);
        for(int i = 0; i<m; i++) {
            vector<int> cur(n,0);
            for(int j =0; j<n; j++) {
                if(i==0 && j==0) {
                    cur[j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i-1>=0) up = prev[j];
                if(j-1>=0) left = cur[j-1];
                cur[j] = up + left;
            }
            prev = cur;
        }
        // return r(m-1,n-1);
        return prev[n-1];
    }
};
