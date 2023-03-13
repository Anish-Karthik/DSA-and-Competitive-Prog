class Solution {
    vector<vector<int>> dp;
    int f(int ind, int amt, vector<int>& coins) {
        if(amt == 0) return 0;
        if(ind == 0) {
            int moves = amt/coins[0];

            if(amt%coins[0]) return dp[0][amt] = 1e8;
            return dp[0][amt] = moves;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int pick = 1e8;
        if(coins[ind] <= amt) pick = 1 + f(ind, amt - coins[ind], coins);
        int notPick = 0 + f(ind-1,amt, coins);

        return dp[ind][amt] = min(pick,notPick);
    }
    int t(int n, int amount, vector<int>& coins) {
        n++;
        dp.assign(n,vector<int>(amount+1, 0));
        for(int amt = 0; amt<= amount; amt++) {
            int moves = amt/coins[0];
            if(amt%coins[0]) dp[0][amt] = 1e8;
            else dp[0][amt] = moves;
        }
        
        for(int ind = 1; ind<n; ind++) {
            for(int amt = 0; amt<= amount; amt++) {
                int pick = 1e8;
                if (amt >= coins[ind]) pick = 1 + dp[ind][amt-coins[ind]];
                int notPick = 0 +  dp[ind-1][amt];

                dp[ind][amt] = min(pick , notPick);
            }
        } 
        return dp[n-1][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp.assign(n,vector<int>(amount+1, -1));
        vector<int> prev(amount+1, 0), cur(amount+1, 0);
        for(int amt = 0; amt<= amount; amt++) {
            int moves = amt/coins[0];
            if(amt%coins[0]) prev[amt] = 1e8;
            else prev[amt] = moves;
        }
        
        for(int ind = 1; ind<n; ind++) {
            for(int amt = 0; amt<=amount; amt++) {
                int pick = 1e8;
                if (amt >= coins[ind]) pick = 1 + cur[amt-coins[ind]];
                int notPick = 0 +  prev[amt];

                cur[amt] = min(pick , notPick);
            }
            prev = cur; 
        } 
        int res = prev[amount];
        // int res = t(n-1, amount, coins);
        return res >= 1e8? -1: res;
    }
};
