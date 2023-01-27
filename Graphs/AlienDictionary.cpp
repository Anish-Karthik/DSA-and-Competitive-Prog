class Solution{
    private:
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
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i = 0 ; i < N-1; i++ ) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            for(int j = 0; j < min(s1.size(),s2.size()); j++) {
                if(s1[j]!=s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }        
            }
        }
        vector<int> topo = topoSort(K,adj);
        string ans = "";
        for(auto it : topo) {
            ans+= char(it + 'a');
        }
        return ans;
    }
};