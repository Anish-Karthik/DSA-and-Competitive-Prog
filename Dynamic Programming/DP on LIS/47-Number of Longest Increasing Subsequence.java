class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int dp[] = new int[n];
        int cnt[] = new int[n];
        for(int i = 0; i<n; i++) {dp[i] = 1; cnt[i] = 1;}
        int len = 1;
        for(int ind = 0; ind<n; ind++) {
            for(int prev = 0; prev<ind; prev++)  {
                if(nums[prev]>=nums[ind]) continue;

                if(dp[ind]< dp[prev] + 1) cnt[ind] = cnt[prev];
                else if(dp[ind] == dp[prev]+1) cnt[ind]+=cnt[prev];
                dp[ind] = Math.max(dp[ind],dp[prev]+1);
            }
            len = Math.max(len,dp[ind]);
        }
        int res = 0;
        for(int i = 0; i<n; i++) {
            if(dp[i] == len) res+=cnt[i] ;
        }
        return res;
    }
}
