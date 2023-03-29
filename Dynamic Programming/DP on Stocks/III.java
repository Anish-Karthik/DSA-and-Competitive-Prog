class Solution {
    int dp[][];
    int f(int ind, int canSell, int[] prices) {
        int n = prices.length;
        if(ind == n || canSell==4) return 0;

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
        int[] next = new int[5];
        int[] cur = new int[5];
        for(int ind = n-1; ind>=0;ind--) {
            cur[0] = Math.max(-prices[ind] + next[1], next[0]);
            cur[1] = Math.max(+prices[ind] + next[2], next[1]);
            cur[2] = Math.max(-prices[ind] + next[3], next[2]);
            cur[3] = Math.max(+prices[ind] + next[4], next[3]);
            next = cur;
        }
        return next[0];
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        // dp = new int[n+1][4+1];
        // for(int i = 0; i<=n; i++) for(int j = 0; j<4; j++) dp[i][j] = -1;
        return so(2,prices);
        // return f(0,0,prices);
        // return t(2,prices);
    }
}
