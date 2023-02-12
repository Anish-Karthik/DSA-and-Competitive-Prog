#include<bits/stdc++.h>
using namespace std;

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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if(ds.findUPar(3) == ds.findUPar(7)){
    	cout<<"Same\n";
    } else{
    	cout<<"not Same\n";
    }
    ds.unionBySize(3, 7);
    if(ds.findUPar(3) == ds.findUPar(7)){
    	cout<<"Same\n";
    } else{
    	cout<<"not Same\n";
    }
    // for(int i =1; i<=7;i++) 
    // 	for(int j = i+1; j<=7; j++) 
    // 	{
    // 		cout<<i<<','<<j<<" : ";
	// 	    if(ds.findUPar(i) == ds.findUPar(j)){
	// 	    	cout<<"Same\n";
	// 	    } else{
	// 	    	cout<<"not Same\n";
	// 	    }
	// 	}
    for(auto x: ds.size) {
    	cout<<x<<' ';
    }
    cout<<endl;
    for(auto x: ds.par) {
    	cout<<x<<' ';
    }
    cout<<endl;

    return 0;
}