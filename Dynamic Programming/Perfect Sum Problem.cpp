//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	int mod = (int)(1e9 + 7);
	
	

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<int> prev(sum + 1, 0);
	    
        prev[0] = 1;
        
        for(int i =1; i<=n; i++){
            vector<int> cur(sum + 1, 0);
            cur[0] = 1;
            for(int j =0; j<=sum; j++){
                
                int notTake = prev[j];
                int take = 0;
                if (arr[i - 1] <= j)
                    take = prev[j - arr[i - 1]];
                
                cur[j] = (notTake + take)%mod;
            }
            prev = cur;
        }    
        return prev[sum] % mod;
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
