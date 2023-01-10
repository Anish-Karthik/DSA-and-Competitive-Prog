#include<bits/stdc++.h>
using namespace std;

int printC(int arr[], int n, int k, int sum=0,  int i = 0) {
	if (sum > k) return 0; //when arr is non negative;
	if (i==n) {
		if (sum==k) return 1;
		return 0;
	}
	return printC(arr, n, k, sum+arr[i], i+1) + printC(arr, n, k, sum, i+1);
}

int main()
{
	int n = 4, k= 6;
    int arr[n]= {3,1,2,4};
    cout<<printC(arr, n, k, 0, 0); //sequences without default args
    //printS(arr,n,k); // using default args significant reduction in args
    return 0;
}