//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod = 1e9+7;
    int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

        if(ind == 0){
                if(target==0 && arr[0]==0)
                    return 2;
                if(target==0 || target == arr[0])
                    return 1;
                return 0;
        }
        
        if(dp[ind][target]!=-1)
            return dp[ind][target];
            
        int notTaken = f(ind-1,target,arr,dp);
        
        int taken = 0;
        if(arr[ind]<=target)
            taken = f(ind-1,target-arr[ind],arr,dp);
            
        return dp[ind][target]= (notTaken + taken)%mod;
    }
    int t(int n, int sum, vector<int>& arr) {
        n+=1;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        
        for(int i = 0; i<n; i++) dp[i][0] = 1;
        if(arr[0]<=sum || arr[0] == 0) dp[0][arr[0]]++;
        
        for(int ind = 1; ind<n; ind++) {
            for(int target = 0; target<=sum; target++ ) {
                int take = 0;
                if(target>= arr[ind]) take = dp[ind-1][target - arr[ind]];
                int notTake = dp[ind-1][target];
                dp[ind][target] = (take+notTake)%mod;
            }
        }
        
        return dp[n-1][sum];
    }
    public:
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int tot = accumulate(arr.begin(),arr.end(),0);
        int sum = (tot-d);
        if(sum <0 || sum%2) return 0;
        sum/=2;
        
        // vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        vector<int> prev(sum+1,0);
        prev[0] = 1;
        if(arr[0]<=sum || arr[0] == 0) prev[arr[0]]++;
        
        for(int ind = 1; ind<n; ind++) {
            vector<int> cur(sum+1,0);
            cur[0] = 1;
            for(int target = 0; target<=sum; target++ ) {
                int take = 0;
                if(target>= arr[ind]) take = prev[target - arr[ind]];
                int notTake = prev[target];
                cur[target] = (take+notTake)%mod;
            }
            prev = cur;
        }
        
        return prev[sum];
        
        // return t(n-1,sum,arr);
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
