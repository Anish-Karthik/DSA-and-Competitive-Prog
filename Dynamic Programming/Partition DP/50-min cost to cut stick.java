class Solution {
    int dp[][];
    int[] arr;
    private int f(int i, int j) {
        if (i>j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = Integer.MAX_VALUE;
        for(int k = i; k<=j; k++) {
            int cost = arr[j+1] - arr[i-1] + f(i,k-1)+ f(k+1,j);
            res = Math.min(res,cost);
        }
        dp[i][j] = res;
        return res;
    }
    int tab() {
        int n = arr.length -2;
        for(int i =0; i<=n+1; i++) for(int j =0; j<=n+1; j++) dp[i][j] = 0;
        for(int i = n; i>=1; i--) {
            for(int j =i; j<=n; j++){
                int res = Integer.MAX_VALUE;
                for(int k = i; k<=j; k++) {
                    int cost = arr[j+1] - arr[i-1]+dp[i][k-1]+dp[k+1][j];
                    res = Math.min(res,cost);
                }
                dp[i][j] = res;
            }
        }
        return dp[1][n];
    }
    public int minCost(int m, int[] cuts) { 
        Arrays.sort(cuts);
        int n = cuts.length;
        arr= new int[n+2];
        dp = new int[n+2][n+2];
        arr[0] = 0;
        for(int i =0; i<n; i++) arr[i+1] = cuts[i];
        for(int i =0; i<=n; i++) for(int j =0; j<=n; j++) dp[i][j] = -1;
        arr[n+1] = m;
        return tab();
        // return f(1,n);
    }
}
