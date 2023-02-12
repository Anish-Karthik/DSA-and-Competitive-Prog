class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, 
        vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n];
        for(auto x: redEdges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back({v,0});
        }
        for(auto x: blueEdges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back({v,1});
        }
        queue< pair<int,pair<int,int>> > q;
        vector<int> dist(n,1e9), par(n,-1);
        vector<vector<int>> vis(n,vector<int>(2));
        dist[0] = 0;
        q.push({0,{0,-1}});
        while(!q.empty()) {
            int u, ewt, color;
            ewt = q.front().first;
            tie(u,color)  = q.front().second;
            q.pop();
            
            for(auto it: adj[u]) {
                int v = it.first;
                int c = it.second;
                if(color == c or vis[v][c]) continue;
                if(1e9 == dist[v]) {
                    dist[v] = ewt + 1;
                }
                vis[v][c] = 1;
                q.push({ewt+1,{v,c}});
            }
        }
        for(int i = 0; i<n; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};