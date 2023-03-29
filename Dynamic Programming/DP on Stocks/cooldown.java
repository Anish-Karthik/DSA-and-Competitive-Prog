class Solution {
    int dp[][];
    int f(int ind, int canSell, int[] prices) {
        int n = prices.length;
        if(ind == n || ind == n+1) return 0;

        if(dp[ind][canSell] != -1) return dp[ind][canSell];
        int profit = 0;
        if(canSell == 0) {
            profit = Math.max(-prices[ind] + f(ind+1,1,prices), f(ind+1,canSell,prices));
        } else {
            profit = Math.max(+prices[ind] + f(ind+2,0,prices), f(ind+1,canSell,prices));
        }
        dp[ind][canSell] = profit;
        return profit;
    }
    int t(int[] prices) {
        int n = prices.length;
        dp = new int[n+2][2];
        for(int ind = n-1; ind>=0;ind--) {
            for(int canSell = 1; canSell>=0; canSell--) {
                int profit = 0;
                if(canSell == 0) {
                    profit = Math.max(-prices[ind] + dp[ind+1][1], dp[ind+1][canSell]);
                } else {
                    profit = Math.max(+prices[ind] + dp[ind+2][0], dp[ind+1][canSell]);
                }
                dp[ind][canSell] = profit;
            }
        }
        return dp[0][0];
    }
    int so(int[] prices) {
        int n = prices.length;
        int skip = 0;
        int[] next = new int[2];
        int[] cur = new int[2];
        for(int ind = n-1; ind>=0;ind--) {
            cur[0] = Math.max(-prices[ind] + next[1], next[0]);
            cur[1] = Math.max(+prices[ind] + skip, next[1]);
            skip = next[0];
            next[0] = cur[0];
            next[1] = cur[1];
        }
        return next[0];
    }
    int sso(int[] prices) {
        int n = prices.length;
        int skip = 0;
        int nextSell = 0, nextNotSell = 0, curNotSell = 0, curSell = 0;
        for(int ind = n-1; ind>=0;ind--) {
            curNotSell = Math.max(-prices[ind] + nextSell, nextNotSell);
            curSell = (Math.max(+prices[ind] + skip, nextSell));
            skip = nextNotSell;
            nextNotSell = curNotSell;
            nextSell = curSell;
        }
        return nextNotSell;
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        // dp = new int[n+1][2];
        // for(int i = 0; i<=n; i++) for(int j = 0; j<2; j++) dp[i][j] = -1;
        return sso(prices);
        // return f(0,0,prices);
        // return t(prices);
    }
}
