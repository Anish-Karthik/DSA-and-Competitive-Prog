class Solution:
    def countWays(self, n, s):
        # code here
        mod = int(1003)
        dp = [[[-1]*(2) for i in range(n+2)] for j in range(n+2)]
        # print(dp)
        def f(i,j,needTrue) :
            
            if i > j: return 0;
            if i == j: 
                if(needTrue): return int(s[i] == 'T')
                else: return int(s[i] == 'F')
                
            if dp[i][j][needTrue] != -1: return dp[i][j][needTrue]
            
            ways = 0     
            for k in range(i+1,j,2):
                lt, rt = f(i,k-1,1) , f(k+1,j,1)
                lf, rf = f(i,k-1,0), f(k+1,j,0)
                if s[k] == '&':
                    if needTrue: ways+= lt * rt;
                    else: ways+= lt * rf + lf * rt + lf * rf;
                elif s[k] == '|':
                    if needTrue: ways+= lt * rf + lf * rt + lt * rt;
                    else: ways+=  lf * rf;
                else:
                    if needTrue: ways+= lt * rf + lf * rt;
                    else: ways+=  lf * rf + lt * rt;
                ways = ways%mod
            dp[i][j][needTrue] = ways
            return ways
        return f(0,n-1,1)
