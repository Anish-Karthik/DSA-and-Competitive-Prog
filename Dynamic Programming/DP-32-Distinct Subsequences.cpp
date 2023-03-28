class Solution {
    int f(int i, int j,string &s, string &t,vector<vector<int>>& dp) {
        if(j==0) return dp[i][0] = 1;
        if(i==0) return dp[0][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];
        int match = 0;
        if(s[i-1] == t[j-1]) match = f(i-1,j-1,s,t,dp);
        int notMatch = f(i-1,j,s,t,dp);
        return dp[i][j] = match + notMatch;
    }
    int f(int m, int n,string s, string t) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i = 0; i <= m; i++) dp[i][0] = 1;
        for(int j = 1; j <= n; j++) dp[0][j] = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int match = 0;
                if(s[i-1] == t[j-1]) match = dp[i-1][j-1];
                int notMatch = dp[i-1][j];
                dp[i][j] = (match + notMatch)%((int)1e9+7);
            }
        }
        return dp[m][n];
    }
    
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        int m = s.size();
        vector<int> prev(n+1,0),cur(n+1,0);
        prev[0] = cur[0] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int match = 0;
                if(s[i-1] == t[j-1]) match = prev[j-1];
                int notMatch = prev[j];
                cur[j] = (match + notMatch)%((int)1e9+7);
            }
            prev = cur;
        }
        return prev[n];
        return f(m,n,s,t);
    }
};
