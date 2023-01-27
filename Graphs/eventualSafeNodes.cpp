#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool cyclic(vector<int> adj[], int node, vector<int> &vis,
            vector<int> &pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto neigh : adj[node]) {
            if(pathvis[neigh]) {
                return true;
            }  
            if(!vis[neigh]) {
                if(cyclic(adj,neigh,vis,pathvis)) return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> pathvis(V,0),vis(V,0),res;
    
        for(int i = 0 ; i < V; i++) {
            if(!pathvis[i]) {
                if(!cyclic(adj,i,vis,pathvis)){
                    res.push_back(i);
                } 
            }
        }
        return res;
    }
};