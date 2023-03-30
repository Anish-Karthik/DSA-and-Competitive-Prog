class Solution {
    int dp[][];
    int f(int ind, int preInd, int[] nums) {
        int n = nums.length;
        if(ind == n+1) return 0;
        if(dp[ind][preInd] != -1) return  dp[ind][preInd];
        int take = 0;
        if(preInd == 0 || nums[preInd-1] < nums[ind-1]) 
            take = 1 + f(ind+1,ind,nums);
        int notTake = 0 + f(ind+1,preInd,nums);
        dp[ind][preInd] = Math.max(take,notTake);
        return dp[ind][preInd];
    }

    int tab(int[] nums) {
        int n = nums.length;
        dp = new int[n+2][n+1];
        for(int ind = n; ind>0; ind--) {
            for(int preInd = n-1; preInd>=0; preInd--)  {
                int take = 0;
                if(preInd == 0 || nums[preInd-1] < nums[ind-1]) 
                    take = 1 + dp[ind+1][ind];
                int notTake = 0 + dp[ind+1][preInd];
                dp[ind][preInd] = Math.max(take,notTake);
            }
        }
        return dp[1][0];
    }
    int so(int[] nums) {
        int n = nums.length;
        int next[] = new int[n+1];
        int cur[] = new int[n+1];
        for(int ind = n; ind>0; ind--) {
            for(int preInd = n-1; preInd>=0; preInd--)  {
                int take = 0;
                if(preInd == 0 || nums[preInd-1] < nums[ind-1]) 
                    take = 1 + next[ind];
                int notTake = 0 + next[preInd];
                cur[preInd] = Math.max(take,notTake);
            }
            next = cur;
        }
        return cur[0];
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        // dp = new int[n+2][n+1];
        // for(int i = 0; i<=n; i++) for(int j = 0; j<=n; j++) dp[i][j] = -1;
        int dp[] = new int[n+1];
        for(int i = 0; i<=n; i++) dp[i] = 1;
        int len = 1;
        for(int ind = 1; ind<n; ind++) {
            for(int prev = 0; prev<ind; prev++)  {
                if(nums[prev]<nums[ind]) 
                    dp[ind] = Math.max(dp[ind],dp[prev]+1);
                len = Math.max(len,dp[ind]);
            }
        }
        
        return len;
        // return f(1,0,nums);
        // return so(nums);
    }
}
