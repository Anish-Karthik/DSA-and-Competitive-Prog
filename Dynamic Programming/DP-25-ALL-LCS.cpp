//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int t(int x, int y, string &s1, string &s2,vector<vector<int>>& dp) {
        
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
    void get(int i, int j, string &s1, string &s2,vector<vector<int>>& dp,
        string tmp, set<string>& res, int size) {
        if(size == 0) {
            reverse(tmp.begin(), tmp.end());
            res.insert(tmp);
            return;
        }
        if(i == 0 or j == 0) return;
        
        for(int row=i;row>0;row--){
            for(int col=j;col>0;col--){
                if(s1[row-1] == s2[col-1]){
                    get(row-1, col-1,s1, s2, dp, tmp + s1[row-1], res, size-1);
                }
            }
        }
            
    }
	public:
		vector<string> all_longest_common_subsequences(string s1, string s2)
		{
		    int n = s1.size();
		    int m = s2.size();
		    vector<vector<int>> dp(n+1,vector<int>(m+1,-1)), vis(n+1,vector<int>(m+1,0));
		    t(n,m,s1,s2,dp);
            
		    
		    set<string> rset;
		    get(n,m,s1,s2,dp,"",rset,dp[n][m]);
		    vector<string> res(rset.begin(),rset.end());
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends
