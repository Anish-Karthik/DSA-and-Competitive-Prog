class Solution:
    def maxCoins(self,nums):
        nums[:] = [1] + nums + [1]
        dp = [[-1] * len(nums) for i in range(len(nums))]
        def f(i,j):
            if i>j: return 0
            if dp[i][j] != -1: return dp[i][j]
            res = -1e9
            for k in range(i,j+1):
                earn = nums[i-1] * nums[k] * nums[j+1] + f(i,k-1)+ f(k+1,j)
                res = max(res,earn)
            dp[i][j] = res
            return res

        def tab():
            n = len(nums)
            for i in range(n): 
                for j in range(n): dp[i][j] = 0
            for i in range(n-2,0,-1):
                for j in range(i,n-1):
                    res = -1e9
                    for k in range(i,j+1):
                        earn = (nums[i-1] * nums[k] * nums[j+1] + 
                                dp[i][k-1]+ dp[k+1][j])
                        res = max(res,earn)
                    dp[i][j] = res
            return dp[1][n-2]
            
        return tab()
        return f(1,len(nums)-2)
