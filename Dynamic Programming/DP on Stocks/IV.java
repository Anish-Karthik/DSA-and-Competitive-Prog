class Solution {
    int dp[][];
    int trans;
    int f(int ind, int canSell, int[] prices) {
        int n = prices.length;
        if(ind == n || canSell==trans*2) return 0;

        if(dp[ind][canSell] != -1) return dp[ind][canSell];
        int profit = 0;
        if(canSell%2 == 0) {
            profit = Math.max(-prices[ind] + f(ind+1,canSell+1,prices), f(ind+1,canSell,prices));
        } else {
            profit = Math.max(+prices[ind] + f(ind+1,canSell+1,prices), f(ind+1,canSell,prices));
        }
        dp[ind][canSell] = profit;
        return profit;
    }
    int t(int k, int[] prices) {
        k = k *2;
        int n = prices.length;
        dp = new int[n+1][k+1];
        for(int ind = n-1; ind>=0;ind--) {
            for(int canSell = k-1; canSell>=0; canSell--) {
                int profit = 0;
                if(canSell%2 == 0) {
                    profit = Math.max(-prices[ind] + dp[ind+1][canSell+1], dp[ind+1][canSell]);
                } else {
                    profit = Math.max(+prices[ind] + dp[ind+1][canSell+1], dp[ind+1][canSell]);
                }
                dp[ind][canSell] = profit;
            }
        }
        return dp[0][0];
    }
    int so(int k, int[] prices) {
        int n = prices.length;
        k = k * 2;
        int[] next = new int[k+1];
        int[] cur = new int[k+1];
        for(int ind = n-1; ind>=0;ind--) {
            for(int canSell = k-1; canSell>=0; canSell--) {
                int profit = 0;
                if(canSell%2 == 0) {
                    profit = Math.max(-prices[ind] + next[canSell+1], next[canSell]);
                } else {
                    profit = Math.max(+prices[ind] + next[canSell+1], next[canSell]);
                }
                cur[canSell] = profit;
            }
            next = cur;
        }
        return next[0];
    }
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        trans = k * 2;
        // dp = new int[n+1][trans+1];
        // for(int i = 0; i<=n; i++) for(int j = 0; j<trans; j++) dp[i][j] = -1;
        return so(k,prices);
        // return f(0,0,prices);
        // return t(k,prices);
    }
}
