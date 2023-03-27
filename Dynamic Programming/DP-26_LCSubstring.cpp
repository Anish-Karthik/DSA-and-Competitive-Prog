//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int t(int x, int y, string &s1, string &s2) {
        int res = 0;
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        for(int i1 = 1; i1<=x; i1++) {
            for(int i2 = 1; i2<=y; i2++) {
                if(s1[i1-1] == s2[i2-1]) dp[i1][i2] = 1 + dp[i1-1][i2-1];   
                res = max(res,dp[i1][i2]);
            }
        }
        return res;
    }
    int s(int x, int y, string &s1, string &s2) {
        int res = 0;
        vector<int> prev(y+1,0), cur(y+1,0);
        for(int i1 = 1; i1<=x; i1++) {
            for(int i2 = 1; i2<=y; i2++) {
                cur[i2] = 0;
                if(s1[i1-1] == s2[i2-1]) cur[i2] = 1 + prev[i2-1];   
                res = max(res,cur[i2]);
            }
            prev = cur;
        }
        return res;
    }
    public:
    int longestCommonSubstr (string &s1, string &s2, int n, int m)
    {
        // your code here
        return s(n,m,s1,s2);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
