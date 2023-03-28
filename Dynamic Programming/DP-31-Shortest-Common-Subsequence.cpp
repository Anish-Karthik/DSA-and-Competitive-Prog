class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int x = s1.size();
        int y = s2.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        
        for(int i1 =0; i1<=x; i1++)  dp[i1][0] = 0;
        for(int i2 =0; i2<=y; i2++)  dp[0][i2] = 0;
        for(int i1 = 1; i1<=x; i1++) {
            for(int i2 = 1; i2<=y; i2++) {
                int match = 0;
                if(s1[i1-1] == s2[i2-1]) match = 1 + dp[i1-1][i2-1];
                int choice1 = 0 + dp[i1-1][i2];
                int choice2 = 0 + dp[i1][i2-1];
                dp[i1][i2] = max(match,max(choice1,choice2));        
            }
        }

        int i1 = x;
        int i2 = y;
        string super;
        while(i1>0 && i2>0) {
            if(s1[i1-1] == s2[i2-1]) {
                super+=s1[i1-1];
                i1--;i2--;
            } else if(dp[i1][i2-1] >= dp[i1-1][i2]){
                super+=s2[i2-1];
                i2--;
            }
            else{
                super+=s1[i1-1]; 
                i1--;
            }
        }
        while(i1>0) {
            super+=s1[i1-1];
            i1--;
        }
        while(i2>0) {
            super+=s2[i2-1]; 
            i2--;
        }
        reverse(super.begin(),super.end());
        return super;
    }
};
