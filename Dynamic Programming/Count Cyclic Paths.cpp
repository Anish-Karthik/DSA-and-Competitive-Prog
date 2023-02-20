class Solution{   
    #define mod (int)(1e9+7)
    int f(int n,int v) {
        if(n == 0) {
            if(v == 0) return 1;
            return 0;
        }
        
        int res = 0;
        for(int i = 0; i<4; i++) {
            if(i == v) continue;
            res += f(n-1,i);
        }
        return res;
    }
    int f(int n,int v,vector<vector<int>>& dp) {
        if(n == 0) {
            if(v == 0) return 1;
            return 0;
        }
        if(dp[n][v]!=-1) return dp[n][v]%mod;
        int res = 0;
        for(int i = 0; i<4; i++) {
            if(i == v) continue;
            res = (res + f(n-1,i,dp)%mod)%mod;
        }
        return dp[n][v] = res%mod;
    }
    int t(int n,vector<vector<int>>& dp) {
        dp[0][0] = 1;
        
        for(int j = 0; j<=n; j++) {
            for(int last = 0; last<4; last++) {  
                for(int i =0; i<4; i++) {
                    if(last == i) continue;
                    if(j-1>=0)
                    dp[j][i] = (dp[j][i] + dp[j-1][last])%mod;
                }
            }
        }
        return dp[n][0];
    }
    int s(int n) {
        vector<int> prev(4,0);
        prev[0] = 1;
        for(int j = 1; j<=n; j++) {
            vector<int> cur(4,0);
            for(int last = 0; last<4; last++) {  
                for(int i =0; i<4; i++) {
                    if(last == i) continue;
                    cur[i] = (cur[i] + prev[last])%mod;
                }
            }
            prev = cur;
        }
        return prev[0];
    }
public:
    int countPaths(int N){
        // code here 
        // vector<vector<int>> dp(N+1,vector<int>(4,0));
        return s(N);
    }
};
