#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, 
    int N,int M, int src){
        // code here
        vector<int> adj[N],dist(N,-1),vis(N,0);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<pair<int,int>> q;
        int dis;
        q.push({src,dis});
        vis[src] = 1;
        while(!q.empty()) {
            tie(src,dis) = q.front();
            q.pop();
            dist[src] = dis;
            for(auto it : adj[src]) {
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,dis+1});
                } 
            }
        }
        
        return dist;
    }
};