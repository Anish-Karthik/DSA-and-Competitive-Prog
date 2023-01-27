#include<bits/stdc++.h>
using namespace std;
xx

class Solution {
  private:
    void dfs(vector<pair<int,int>> adj[], int node, vector<int> &vis,
        stack<int> &st) {
        vis[node] = 1;
        for(auto neigh: adj[node]) {
            if(!vis[neigh.first]) {
                dfs(adj,neigh.first,vis,st);
            }
        }
        st.push(node);
    }

  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> vis(N,0);
	    stack<int> st;
        dfs(adj,0,vis,st);
	    int node = st.top();
        st.pop();
	    vector<int> dist(N,1e9);
	    dist[node] = 0;
	    while(!st.empty()){
	        for(auto it: adj[node]) {
	            dist[it.first] = min(dist[it.first],dist[node]+
	            it.second);
	        }
	        node = st.top();
	        st.pop();
	    }
	    for(int i = 0; i < N; i++){
	        if(dist[i] == 1e9) dist[i] = -1;
	    }
	    return dist;
    }
};