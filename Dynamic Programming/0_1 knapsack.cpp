//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    vector<vector<int>> dp;
    
    int f(int ind,int cap, int val[], int wt[]) {
        
        if(cap == 0) return 0;
        if(ind == 0) {
            if(wt[0] <= cap) return val[0];
            return 0;
        }
        if(dp[ind][cap] != -1) return dp[ind][cap];
        auto pick = 0;
        if (cap >= wt[ind]) pick = val[ind] + f(ind-1,cap-wt[ind], val, wt);
        auto notPick = 0 + f(ind-1,cap,val,wt);
        
        return dp[ind][cap] = max(pick , notPick);
    }
    int t(int n, int W, int val[], int wt[]) {
        n++;
       dp.assign(n,vector<int>(W+1, 0));
       for(int i = wt[0]; i<=W; i++) dp[0][i] = val[0];
       
       for(int ind = 1; ind<n; ind++) {
           for(int cap = 0; cap<= W; cap++) {
                auto pick = 0;
                if (cap >= wt[ind]) pick = val[ind] + dp[ind-1][cap-wt[ind]];
                auto notPick = 0 +  dp[ind-1][cap];
                
                dp[ind][cap] = max(pick , notPick);
           }
       } 
       return dp[n-1][W];
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<int> prev(W+1, 0);
        for(int i = wt[0]; i<=W; i++) prev[i] = val[0];
        
        for(int ind = 1; ind<n; ind++) {
           for(int cap = W; cap>= 0; cap--) {
                auto pick = 0;
                if (cap >= wt[ind]) pick = val[ind] + prev[cap-wt[ind]];
                auto notPick = 0 +  prev[cap];
                
                prev[cap] = max(pick , notPick);
           }
        } 
       return prev[W];
       
    //   return t(n-1, W, val, wt);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
