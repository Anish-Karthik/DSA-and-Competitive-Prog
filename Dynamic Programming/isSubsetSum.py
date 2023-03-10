#User function Template for python3

class Solution:
    
    def isSubsetSum (self, n, arr, k):
        # code here 
        prev = [True] + [False]*k
        if arr[0] <= k: prev[arr[0]] = True
        for ind in range(1,n):
            cur = [True] + [False]*k
            for target in range(k+1):
                take = False
                if target >= arr[ind]:
                    take = prev[target-arr[ind]]
                notTake = prev[target]
                cur[target] = take or notTake
            prev = cur
        return prev[k]
        
        def f(ind,target):
            # global dp
            # try:
            #     if dp:
            #         pass
            #     if ind == n - 1 and (len(dp) != n or len(dp[0]) != k):
            #         raise error()
            # except:
            #     dp = [[-1]*(k+1) for i in range(n)]
            if target == 0:
                return True
            if ind == 0:
                return arr[ind] == target
            
            if dp[ind][target] != -1: return dp[ind][target]
            
            take = False
            if target >= arr[ind]:
                take = f(ind-1,target-arr[ind])
            notTake = f(ind-1,target)
            dp[ind][target] = take or notTake
            return dp[ind][target] 
        
        def t(ind,target):
            dp = [[False]*(k+1) for i in range(n)]
            
            for i in range(n):
                dp[i][0] = True
            if arr[0] <= k: dp[0][arr[0]] = True
            
            for ind in range(1,n):
                for target in range(k+1):
                    take = False
                    if target >= arr[ind]:
                        take = dp[ind-1][target-arr[ind]]
                    notTake = dp[ind-1][target]
                    dp[ind][target] = take or notTake
            return dp[n-1][k]
        
        
        
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        arr = input().split()
        for itr in range(N):
            arr[itr] = int(arr[itr])
        sum = int(input())

        ob = Solution()
        if ob.isSubsetSum(N,arr,sum)==True:
            print(1)
        else :
            print(0)
            
        

# } Driver Code Ends
