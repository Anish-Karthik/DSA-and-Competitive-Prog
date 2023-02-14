//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    vector<int> dp;
    int f(int n, vector<int>&a) {
        if( n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int one = abs(a[n] - a[n-1]) + f(n-1, a);
        int two = one; 
        if (n > 1)
            two = abs(a[n] - a[n-2]) + f(n-2, a);
        return dp[n] = min(one, two);
    }
    
    int t(int n, vector<int>&a) {
        dp[0] = 0;
        for(int i = 1; i<=n; i++) {
            
            int left = abs(a[i] - a[i-1]) + dp[i - 1];
            int right = left;
            if( i > 1)
                right = abs(a[i] - a[i-2]) + dp[i-2];
            dp[i] = min(left, right);
        }
        return dp[n];
    }
    
    int s(int n, vector<int>&a) {
        int prev = 0, prev2 = 0;
        for(int i = 1; i <= n; i++) {
            int left = abs(a[i] - a[i-1]) + prev;
            int right = left;
            if(i > 1)
                right = abs(a[i] - a[i-2]) + prev2;
            prev2 = prev;
            prev = min(left, right);
        }
        return prev;
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        if(n == 1) return 0;
        // Code here
        // dp.resize(n , -1);
        return s(n-1,height);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
