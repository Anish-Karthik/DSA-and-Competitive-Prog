class Solution {
    int k,n;
    vector<int> arr,dp;
    int f(int i) {
        if(i == n) return 0;
        if(dp[i]!=-1) return dp[i];
        int res = 0;
        int mx = arr[i];
        for(int j = i; j<min(i+k,n); j++) {
            mx = max(mx,arr[j]);
            res = max(res, mx*(j-i+1) + f(j+1));
        }
        dp[i] = res;
        return res;
    }
    int tab() {
        dp[n] = 0;
        for(int i = n-1; i>=0; i--) {
            int res = 0;
            int mx = arr[i];
            for(int j = i; j<min(i+k,n); j++) {
                mx = max(mx,arr[j]);
                res = max(res, mx*(j-i+1) + dp[j+1]);
            }
            dp[i] = res;
        }
        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k = k; this->arr = arr;
        n = arr.size();
        dp.assign(n+1,-1);
        return tab();
        return f(0);
    }
};
