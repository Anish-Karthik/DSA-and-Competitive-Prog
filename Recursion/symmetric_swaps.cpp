#include<bits/stdc++.h>
using namespace std;

int printS(int arr[],int b[], int n, vector<int> ds,
	int i = 0) {

	if (i==n) {
		int val = *max_element(ds.begin(),ds.end())-
			*min_element(ds.begin(),ds.end());
		// cout<<"diff: "<<val<<endl;
		return val;
	}
	int tmp = ds[i];
	ds[i]=b[i];
	int c = printS(arr, b, n, ds, i+1);
	ds[i]=tmp;
	int d = printS(arr, b, n, ds, i+1);
	return min(c,d);
}

int main()
{
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int a[n],b[n];
	    vector<int> c(n);
	    for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=0;i<n;i++) cin>>b[i],c[i]=a[i];
	    int res = printS(a,b,n,c,0);
	    cout<<res<<endl;
	}
    return 0;
}