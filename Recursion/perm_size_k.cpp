#include<bits/stdc++.h>
using namespace std;
/*
	T.C = O(nPk * k)
	S.C = O(k)
*/
void perm(string &s, vector<string> &res, vector<char> &ds, 
	vector<bool> &vis,int k) {
	//O(k) copy (k) + append (k)
	if (ds.size()==k) {
		string tmp(k,'1');
		for(int i =0; i<s.size();i++) tmp[i] = ds[i];
		res.push_back(tmp);
		return;
	}

	for(int i = 0;i<s.size();i++) {
		if(!vis[i]) {
			ds.push_back(s[i]);
			vis[i] = true;
			perm(s,res,ds,vis,k); 
			vis[i] = false;
			ds.pop_back();
		}
	}

}

int main()
{
    vector<string> res;
    string s = "abcde";
    vector<char> ds;
    vector<bool> vis(s.size(),false);
    perm(s,res,ds,vis, 3);
    for(string x: res) {
    	cout<<x<<endl;
    }
    return 0;
}