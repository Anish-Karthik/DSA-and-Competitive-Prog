#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void printS(vector<int> &arr, int k, vector<vector<int>> &res,vector<int> &ds, int ind) {
        int n = arr.size();
        //if (sum > k) return; //when arr is non negative;
        if (!k) {
            res.push_back(ds); //O(n)
            return;
        }
        for (int i = ind; i < n; i++) {
            if (i>ind && arr[i]==arr[i-1]) continue;
            if (arr[i] > k) break;
            ds.push_back(arr[i]);
            printS(arr, k-arr[i], res, ds, i+1);
            ds.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target)    {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> ds;
        vector<vector<int>> res;
        printS(arr,target, res, ds, 0);
        return res;
    }
};
int main()
{
    int n = 4, k= 3;
    Solution sol;
    vector<int> arr= {1,1,2,2};
    //we sort at beginning to to avois O(2^n * n )--> O(2^n * log(2^n))
    // T.c : O((2^n * n) + (n * log(n)) = O(2^n * n )
    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> res=sol.combinationSum2(arr, k);
    // sorting subsequences array will take 2^n * log(2^n)
    //;// O()

    for(auto comb: res) {
        for (auto x: comb) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}