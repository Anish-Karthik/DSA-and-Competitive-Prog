#include<bits/stdc++.h>
using namespace std;

void printS(int arr[], int n, vector<int> ds={}, int i = 0) {

	if (i==n) {
		for (auto x: ds) {
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}
	//pick
	ds.push_back(arr[i]);
	printS(arr, n, ds, i+1);
	ds.pop_back();

	//not pick
	printS(arr, n, ds, i+1);
}

int main()
{
	int n = 4;
    int arr[n]= {3,1,2,4};
    vector<int> ds;
    printS(arr,n);
    //printS(arr,n,ds,0); //sequences without default args
    return 0;
}