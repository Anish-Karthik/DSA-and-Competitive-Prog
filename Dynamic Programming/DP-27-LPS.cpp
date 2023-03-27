//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int f(int i1, int i2, string &s1, string &s2, vector<vector<int>>& dp) {
        if(i1 == 0 or i2 == 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        int match = 0;
        if(s1[i1-1] == s2[i2-1]) match = 1 + f(i1-1, i2-1, s1,s2,dp);
        int choice1 = 0 + f(i1-1,i2,s1,s2,dp);
        int choice2 = 0 + f(i1,i2-1,s1,s2,dp);
        return dp[i1][i2] = max(match,max(choice1,choice2));
    }
    int t(int x, int y, string &s1, string &s2) {
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
        return dp[x][y];
    }
    int s(int x, int y, string &s1, string &s2) {
        vector<int> prev(y+1,0), cur(y+1,0);
        for(int i1 = 1; i1<=x; i1++) {
            for(int i2 = 1; i2<=y; i2++) {
                int match = 0;
                if(s1[i1-1] == s2[i2-1]) match = 1 + prev[i2-1];
                int choice1 = 0 + prev[i2];
                int choice2 = 0 + cur[i2-1];
                cur[i2] = max(match,max(choice1,choice2));        
            }
            prev = cur;
        }
        return cur[y];
    }
    int lcs(int x, int y, string &s1, string &s2)
    {
        // vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        return s(x,y,s1,s2);
    }
  public:
    int longestPalinSubseq(string s1) {
        string s2(s1.rbegin(),s1.rend());
        return lcs(s1.size(),s2.size(),s1,s2);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
