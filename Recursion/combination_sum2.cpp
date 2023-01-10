#include<bits/stdc++.h>
using namespace std;

// similar to print all subsequences but order doesn't matter + no duplicate in res

//combinations not to be repeated using set takes logn extra thus 
// O(2^n * n * logn)
// O(comb * copy * set)


//skipping same values for each index to avoid to duplication
// O(2^n * n)
void printS(int arr[], int n, int k, vector<vector<int>> &res,vector<int> ds={}, int sum=0,  int ind = 0) {
	if (sum > k) return; //when arr is non negative;
	if (sum ==k) {
		res.push_back(ds); //O(n)
		return;
	}

	for (int i = ind; i < n; i++) {
		if (i>ind && arr[i]==arr[i-1]) continue;
		if (arr[i]+sum > k) break;
		ds.push_back(arr[i]);
		printS(arr, n, k, res, ds, sum+arr[i], i+1);
		ds.pop_back();
	}
}

int main()
{
	int n = 4, k= 3;
    int arr[n]= {1,1,2,2};
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