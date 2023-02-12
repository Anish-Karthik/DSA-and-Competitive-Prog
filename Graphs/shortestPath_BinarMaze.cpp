//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({source,0});
        vis[source.first][source.second] = 1;
        while(!q.empty()) {
            int dist = q.front().second;
            auto node = q.front().first;
            q.pop();
            if(node == destination) return dist;
            for(int i = 0; i < 4; i++) {
                int nrow = delrow[i]+node.first;
                int ncol = delcol[i]+node.second;
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && 
                grid[nrow][ncol] && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends