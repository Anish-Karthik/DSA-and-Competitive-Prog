#include<bits/stdc++.h>
using namespace std;

void printS(int arr[], int n,int k, vector<int> ds={}, int sum=0,  int i = 0) {
	if (sum > k) return; //when arr is non negative;
	if (i==n) {
		if (sum==k){
			for (auto x: ds) {
				cout<<x<<" ";
			}
			cout<<endl;
		}
		return;
	}
	//pick
	sum+=arr[i];
	ds.push_back(arr[i]);
	printS(arr, n, k, ds, sum, i+1);
	ds.pop_back();
	sum-=arr[i];
	//not pick
	printS(arr, n, k, ds, sum, i+1);
}

int main()
{
	int n = 4, k= 3;
    int arr[n]= {3,1,2,4};
    vector<int> ds;
    printS(arr, n, k, ds, 0, 0); //sequences without default args
    //printS(arr,n,k); // using default args significant reduction in args
    return 0;
}