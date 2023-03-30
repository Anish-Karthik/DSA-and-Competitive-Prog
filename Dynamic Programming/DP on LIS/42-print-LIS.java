class Solution{
    public ArrayList<Integer> longestIncreasingSubsequence(int n, int nums[]){
        // Code here]
        ArrayList<Integer> res = new ArrayList<>();
        int dp[] = new int[n+1];
        int loc[] = new int[n+1];
        dp[0] = 1;
        loc[0] = 0;
        int len = 1;
        int start = 0;
        for(int ind = 1; ind<n; ind++) {
            dp[ind] = 1;
            loc[ind] = ind;
            for(int prev = 0; prev<ind; prev++)  {
                if(nums[prev]<nums[ind]) {
                    if(dp[ind] < dp[prev]+1) loc[ind] = prev;
                    dp[ind] = Math.max(dp[ind],dp[prev]+1);
                }
                if(len<dp[ind]) start = ind;
                len = Math.max(len,dp[ind]);
            }
        }
        while(loc[start] != start) {
            res.add(nums[start]);
            start = loc[start];
        }
        res.add(nums[start]);
        Collections.reverse(res);
        return res;
    }
}
