//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int ind, int w, int val[], int wt[],vector<vector<int>> &dp) {
        
        if(ind == 0) return dp[0][w] = val[0] * (w/wt[0]);
        if(dp[ind][w] != -1)  return dp[ind][w];
        int notPick = f(ind-1,w,val,wt,dp);
        int pick  = 0;
        if(wt[ind] <= w) pick = val[ind] + f(ind,w-wt[ind],val,wt,dp);
        return dp[ind][w] = max(pick,notPick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return f(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
