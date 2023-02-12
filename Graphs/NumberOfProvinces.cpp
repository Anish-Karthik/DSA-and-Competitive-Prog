//{ Driver Code Starts
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



class Solution {
    
    void bfs(vector<int> adjL[],int node, bool vis[]) {
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            node = q.front(),q.pop();
            for(auto neigh: adjL[node]) {
                if(!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        for (int i = 0; i < V; i++ ) {
            for (int j = 0; j < V; j++) {
                if(adj[i][j] == 0) continue;
                if(ds.findUPar(i) == ds.findUPar(j)) continue;
                ds.unionBySize(i,j);
            }
        }
        int cnt =0;
        
        for (int i = 0; i < V; i++ ) {
            if(ds.findUPar(i) == i) cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends