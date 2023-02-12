#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // prims
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> vis(V,0);
        int mst = 0;
        int cnt = 0;
        pq.push({0,0});
        while(!pq.empty()) {
            int node,curWt;
            tie(curWt,node) = pq.top();
            pq.pop();
            if(vis[node]) continue;
            cnt++;
            vis[node] = 1;
            mst += curWt;
            if(cnt == V) break;
            for(auto it: adj[node]) {
                int neigh = it[0];
                int wt = it[1];
                if(!vis[neigh]) pq.push({wt, neigh});
            }
        }
        return mst;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends