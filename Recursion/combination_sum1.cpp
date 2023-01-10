#include<bits/stdc++.h>
using namespace std;

void printS(int arr[], int n,int k, vector<vector<int>> &res,vector<int> ds={}, int sum=0,  int i = 0) {
	if (sum > k) return; //when arr is non negative;
	if (i==n) {
		if (sum==k) res.push_back(ds); //O(n)
		return;
	}
	//pick
	ds.push_back(arr[i]);
	printS(arr, n, k, res, ds, sum+arr[i], i);
	ds.pop_back();
	printS(arr, n, k, res, ds, sum, i+1);
}

int main()
{
	int n = 4, k= 3;
    int arr[n]= {3,1,2,4};
    //we sort at beginning to to avois O(2^n * n )--> O(2^n * log(2^n))
    // T.c : O((2^n * n) + (n * log(n)) = O(2^n * n )
    sort(arr,arr+n);
    vector<int> ds;
    vector<vector<int>> res;
    printS(arr, n, k, res, ds, 0, 0);
    // sorting subsequences array will take 2^n * log(2^n)
    //sort(res.begin(), res.end());// O()


   	for(auto comb: res) {
    	for (auto x: comb) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
    return 0;
}