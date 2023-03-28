class Solution {
    // p = "RE" // itr = i
    // t = "string" // itr = j
    bool f(int i, int j, string& p, string& t,vector<vector<int>> &dp) {
        if(j == 0) {
            //if * at start of string
            while(i>0 && p[i-1] == '*') i--;
            if(i == 0) return dp[0][0] = true;
            return false;
        }
        if(i == 0) return dp[0][j] = false;

        if(dp[i][j] != -1) return dp[i][j];
        bool match = false;
        if(p[i-1] == t[j-1] or p[i-1] == '?') match = f(i-1,j-1,p,t,dp);
        if(p[i-1] == '*') match = match || f(i,j-1,p,t,dp) || f(i-1,j,p,t,dp);
        return dp[i][j]  = match;
    }
    bool tab(int m, int n, string& p, string& t,vector<vector<int>> &dp) {
        for(int j = 1; j<=n; j++) dp[0][j] = false;
        for(int i = 1; i<=m ; i++) {
            int k = i;
            while(i>0 && p[i-1] == '*') i--;
            if(i == 0) dp[k][0] = true;          
            else dp[k][0] = false;
            i = k;
        }
        dp[0][0] = true;
        for(int i = 1; i<=m; i++) {
            for(int j = 1; j<=n; j++) {
                bool match = false;
                if(p[i-1] == t[j-1] or p[i-1] == '?') match = dp[i-1][j-1];
                else if(p[i-1] == '*')  match = match || dp[i][j-1] || dp[i-1][j];
                dp[i][j]  = match;
            }
        }
        return dp[m][n];
    }
public:
    bool isMatch(string t, string p) {
        int m = p.size();
        int n = t.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        vector<bool> prev(n+1,0),cur(n+1,0);
        prev[0] = true;
        for(int i = 1; i<=m; i++) {
            int k = i;
            while(i>0 && p[i-1] == '*') i--;
            if(i == 0) cur[0] = true;          
            else cur[0] = false;
            i = k;
            for(int j = 1; j<=n; j++) {
                bool match = false;
                if(p[i-1] == t[j-1] or p[i-1] == '?') match = prev[j-1];
                else if(p[i-1] == '*')   match = match || cur[j-1] || prev[j];
                cur[j]  = match;
            }
            prev = cur;
        }
        return prev[n];
        
        // return tab(m,n,p,t,dp);
    }
};
