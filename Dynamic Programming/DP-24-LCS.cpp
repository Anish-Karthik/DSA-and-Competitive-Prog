//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
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
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string &s1, string &s2)
    {
        // vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        return s(x,y,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
