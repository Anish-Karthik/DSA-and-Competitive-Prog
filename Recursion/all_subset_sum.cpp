#include<bits/stdc++.h>
using namespace std;

void printS(int arr[], int n, vector<int> &ds, int i = 0, int sum = 0 ) {
	if (i==n) {
		ds.push_back(sum);
		return;
	}
	printS(arr, n, ds, i+1,sum);
	printS(arr, n, ds, i+1,sum+arr[i]);
}

int main()
{
	int n = 4;
    int arr[n]= {3,1,2,4};
    sort(arr, arr+n);
    vector<int> ds;
    printS(arr,n,ds,0,0); //sequences without default args
    for (auto x: ds) {
		cout<<x<<" ";
	}
	cout<<endl;	
    return 0;
}