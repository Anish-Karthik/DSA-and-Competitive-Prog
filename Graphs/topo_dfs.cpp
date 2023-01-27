#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void dfs(vector<int> adj[], int node, vector<int> &vis,
        stack<int> &st) {
        vis[node] = 1;
        for(int neigh: adj[node]) {
            if(!vis[neigh]) {
                dfs(adj,neigh,vis,st);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> st;
	    for(int i = 0; i<V; i++) {
	        if(!vis[i]) {
	            dfs(adj,i,vis,st);
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};