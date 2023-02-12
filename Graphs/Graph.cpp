#include<bits/stdc++.h>
using namespace std;

class Graph {
	private:
		vector<vector<int>> adjL;
		vector<vector<int>> adjM;
		vector<vector<int>> edges;
		bool isWeighted;
		bool isDirected;
	Graph(bool isDirected = false,bool isWeighted = false) {
		this.isDirected = isDirected;
		this.isWeighted = isWeighted;
	}
	Graph(vector<vector<int>> &edges,bool isDirected = false) {
		this.edges = edges;
		this.isDirected = isDirected;
		for(auto it: edges) {
			adjL[it[0]].push_back(it[1]);
			if(!isDirected)
			adjL[it[1]].push_back(it[0]);
		}
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}