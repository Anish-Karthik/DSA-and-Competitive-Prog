//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    int r(int n, int prev, vector<vector<int>>& a) {
        if(n == 0) {
            int maxi = 0;
            for(int i = 0; i < 3; i++) {
                if( i != prev ) {
                    maxi = max(a[0][i], maxi);
                }
            }
            return maxi;
        }
        
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if( i != prev ) {
                maxi = max(a[n][i] + r(n-1, i, a),maxi);
            }
        }
        return maxi;
    }
    
    int f(int n, int prev, vector<vector<int>>& a, vector<vector<int>>& dp) {
        if(n == 0) {
            int maxi = 0;
            for(int i = 0; i < 3; i++) {
                if( i != prev ) {
                    maxi = max(a[0][i], maxi);
                }
            }
            return maxi;
        }
        if(prev!=-1 && dp[n][prev] != -1) return dp[n][prev];
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if( i != prev ) {
                maxi = max(a[n][i] + f(n-1, i, a, dp),maxi);
            }
        }
        if(prev == -1) {
            return maxi;
        }
        return dp[n][prev] = maxi;
    }
    int t(int n, int prev, vector<vector<int>>& a, vector<vector<int>>& dp) {

        dp[0][0] = max(a[0][1],a[0][2]);
        dp[0][1] = max(a[0][0],a[0][2]);
        dp[0][2] = max(a[0][1],a[0][0]);
        dp[0][3] = max(a[0][1], max(a[0][2],a[0][0]) );
        for(int day = 1; day<=n; day++){
            for(int prev = 0; prev < 4; prev++) {
                dp[day][prev] = 0;
                for(int task = 0; task < 3; task++){
                    if( task != prev) {
                        dp[day][prev] = max(dp[day][prev], a[day][task] + dp[day-1][task]);
                    }
                }
            }
        }
        return dp[n][3];
    }
    int s(int n, int prev, vector<vector<int>>& a) {
        vector<int> dp(4);
        dp[0] = max(a[0][1],a[0][2]);
        dp[1] = max(a[0][0],a[0][2]);
        dp[2] = max(a[0][1],a[0][0]);
        dp[3] = max(a[0][1], max(a[0][2],a[0][0]) );
        for(int day = 1; day<=n; day++){
            vector<int> tmp(4);
            for(int prev = 0; prev < 4; prev++) {
                tmp[prev] = 0;
                
                for(int task = 0; task < 3; task++){
                    if( task != prev) {
                        tmp[prev] = max(tmp[prev], 
                            a[day][task] + dp[task]);
                    }
                }
            }
            dp = tmp;
        }
        return dp[3];
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        // vector<vector<int>> dp(n, vector<int>(4,-1)); 
        int res = s(n-1, 3, points);
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
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
