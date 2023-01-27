#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> topo;
	    int indeg[V] ={0};
	    queue<int> q;
	    
	    for(int i = 0; i<V; i++) {
	        for(int neigh: adj[i]) indeg[neigh]++;
	    }
	    for(int i = 0; i < V; i++) {
	        if(indeg[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(int neigh : adj[node]) {
	            indeg[neigh]--;
	            if(indeg[neigh] == 0) q.push(neigh);
	        }
	    }
	    return topo;
	}
};