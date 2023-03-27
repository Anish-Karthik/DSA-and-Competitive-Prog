//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int ind, int k, int price[],vector<vector<int>> &dp) {
        
        if(ind == 0) return dp[0][k] = price[0] * k;
        if(dp[ind][k] != -1)  return dp[ind][k];
        int notPick = f(ind-1,k,price,dp);
        int pick  = 0;
        if(ind+1 <= k) pick = price[ind] + f(ind,k-(ind+1),price,dp);
        return dp[ind][k] = max(pick,notPick);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
