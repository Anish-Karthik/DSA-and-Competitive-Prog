class Solution {
    int n;
    string s;
    vector<int> dp;
    bool isPal(int i, int j) {
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int f(int i) {
        if(i==n) return -1;
        if(dp[i]!=-1) return dp[i];

        int res = n;
        for(int j = i; j<n; j++) {
            if(isPal(i,j)) res = min(res, 1 + f(j+1)); 
        }
        dp[i] = res;
        return res;
    }
    int tab() {
        for(int i = n-1; i>=0; i--) {
            int res = n;
            for(int j = i; j<n; j++) {
                if(isPal(i,j)) res = min(res, 1 + dp[j+1]); 
            }
            dp[i] = res;
        }
        return dp[0];
    }
public:
    int minCut(string &s) {
        n = s.size();
        this->s = s;
        dp.assign(n+1,-1);
        return tab();
        return f(0);
    }
};
