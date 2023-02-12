//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{

public:
	vector<int> rank,size,par;
public:
	DisjointSet(int n) {
		rank.resize(n+1,0);
		par.resize(n+1,0);
		size.resize(n+1,1);
		for(int i =0; i<n+1; i++) {
			par[i] = i;
		}
	}
public:
	void unionByRank(int u, int v) {
		int pu = findUPar(u);
		int pv = findUPar(v);
		if (pu == pv) return;
		if (rank[pu] == rank[pv]) {
			rank[pu]++;
			par[pv] = pu;
		} else if(rank[pu] > rank[pv]) {
			par[pv] = pu;
		} else {
			par[pu] = par[pv];
		}
	}
public:
	void unionBySize(int u, int v) {
		int pu = findUPar(u);
		int pv = findUPar(v);
		if (pu == pv) return;
		if(size[pu] >= size[pv]) {
			par[pv] = pu;
			size[pu] += size[pv];
		} else {
			par[pu] = pv;
			size[pv] += size[pu];
		}
	}
public:
	int findUPar(int u) {
		if(par[u] == u) return u;
		return par[u] = findUPar(par[u]);
	}
};


class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size();
    	DisjointSet ds(n);
    	unordered_map<string,int> mmap;
    	for(int i = 0; i<n; i++) {
    		int m = accounts[i].size();
    		for(int j = 1; j<m; j++) {
    			string &mail = accounts[i][j];
    			if(mmap.count(mail)) {
    				ds.unionBySize(mmap[mail],i);
    			} else {
    				mmap[mail] = i;
    			}
    		}
    	}
    	vector<string> mergedAccounts[n];
    	for(auto it: mmap) {
    	    auto& mail = it.first; 
    		int userId = ds.findUPar(it.second);
    		mergedAccounts[userId].push_back(mail);
    	}

    	vector<vector<string>> ans;

    	for(int i = 0; i<n; i++) {
    		if(mergedAccounts[i].size() == 0) continue;
    		sort(mergedAccounts[i].begin(), mergedAccounts[i].end());
    		vector<string> tmp;
    		tmp.push_back(accounts[i][0]);
    		tmp.insert(tmp.end(),mergedAccounts[i].begin(),mergedAccounts[i].end());
    		ans.push_back(tmp);
    	}
    	return ans;
    }
};




//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends