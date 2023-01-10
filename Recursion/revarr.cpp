/*
    reverse an array recursively using pseudo 2 pointer
    i, n-i-1 be indices
    T.c = O(n), N/2
    s.c = O(n), N/2 stack depth
*/
#include<bits/stdc++.h>
using namespace std;

void revarr(int arr[], int n, int i=0) {
    if (i == n/2) return;
    swap(arr[i],arr[n-i-1]);
    revarr(arr, n, i+1);
} 

int main()
{
    int n = 5;
    int arr[n]= {1,4,6,3,7};
    revarr(arr,n);
    //revarr(arr,n,0)//also works
    for(auto x: arr) {
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}