#include<bits/stdc++.h>
using namespace std;

void printS(int arr[], int n, vector<vector<int>> &res, vector<int> &ds, int ind = 0) {
	if (ind==n) {
		res.push_back(ds);
		return;
	}
	for (int i = ind; i < n; i++) {
		if (i>ind && arr[i]==arr[i-1]) continue;
		ds.push_back(arr[i]);
		printS(arr, n,res, ds, i+1);
		ds.pop_back();
	}
}

int main()
{
	int n = 4;
    int arr[n]= {3,1,2,4};
    sort(arr, arr+n);
    vector<int> ds;
    vector<vector<int>> res;
    printS(arr,n,res,ds,0); //sequences without default args
    for(auto ds: res){
	    for (auto x: ds) {
			cout<<x<<" ";
		}
		cout<<endl;	
	}
    return 0;
}