//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
    private:
    int r(int n, int prev, vector<vector<int>>& a) {
        if(n == 0) {
            int maxi = 1e9;
            for(int i = 0; i < 3; i++) {
                if( i != prev ) {
                    maxi = min(a[0][i], maxi);
                }
            }
            return maxi;
        }
        
        int maxi = 1e9;
        for(int i = 0; i < 3; i++) {
            if( i != prev ) {
                maxi = min(a[n][i] + r(n-1, i, a),maxi);
            }
        }
        return maxi;
    }
    
    int f(int n, int prev, vector<vector<int>>& a, vector<vector<int>>& dp) {
        if(n == 0) {
            int maxi = 1e9;
            for(int i = 0; i < 3; i++) {
                if( i != prev ) {
                    maxi = min(a[0][i], maxi);
                }
            }
            return maxi;
        }
        if(prev!=-1 && dp[n][prev] != -1) return dp[n][prev];
        int maxi = 1e9;
        for(int i = 0; i < 3; i++) {
            if( i != prev ) {
                maxi = min(a[n][i] + f(n-1, i, a, dp),maxi);
            }
        }
        if(prev == -1) {
            return maxi;
        }
        return dp[n][prev] = maxi;
    }
    int t(int n, int prev, vector<vector<int>>& a, vector<vector<int>>& dp) {

        dp[0][0] = min(a[0][1],a[0][2]);
        dp[0][1] = min(a[0][0],a[0][2]);
        dp[0][2] = min(a[0][1],a[0][0]);
        dp[0][3] = min(a[0][1], min(a[0][2],a[0][0]) );
        for(int day = 1; day<=n; day++){
            for(int prev = 0; prev < 4; prev++) {
                dp[day][prev] = 1e9;
                for(int task = 0; task < 3; task++){
                    if( task != prev) {
                        dp[day][prev] = min(dp[day][prev], a[day][task] + dp[day-1][task]);
                    }
                }
            }
        }
        return dp[n][3];
    }
    int s(int n, int prev, vector<vector<int>>& a) {
        vector<int> dp(4);
        dp[0] = min(a[0][1],a[0][2]);
        dp[1] = min(a[0][0],a[0][2]);
        dp[2] = min(a[0][1],a[0][0]);
        dp[3] = min(a[0][1], min(a[0][2],a[0][0]) );
        for(int day = 1; day<=n; day++){
            vector<int> tmp(4);
            for(int prev = 0; prev < 4; prev++) {
                tmp[prev] = 1e9;
                
                for(int task = 0; task < 3; task++){
                    if( task != prev) {
                        tmp[prev] = min(tmp[prev], 
                            a[day][task] + dp[task]);
                    }
                }
            }
            dp = tmp;
        }
        return dp[3];
    }
public:
    int minCost(vector<vector<int>> &colors, int n) {
        // Write your code here.
        int res = s(n-1, 3, colors);
        // for(auto it: dp) {
            
        //     for(auto x: it) {
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
