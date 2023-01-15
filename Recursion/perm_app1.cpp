#include<bits/stdc++.h>
using namespace std;
/*
	T.C = O(n!* n)
	S.C = O(n)
*/
void perm(string &s, vector<string> &res, vector<char> &ds, 
	vector<bool> &vis) {
	//O(n) copy (n) + append (n)
	if (ds.size()==s.size()) {
		string tmp(s.size(),'1');
		for(int i =0; i<s.size();i++) tmp[i] = ds[i];
		res.push_back(tmp);
		return;
	}

	for(int i = 0;i<s.size();i++) {
		if(!vis[i]) {
			ds.push_back(s[i]);
			vis[i] = true;
			perm(s,res,ds,vis); 
			vis[i] = false;
			ds.pop_back();
		}
	}

}

int main()
{
    vector<string> res;
    string s = "abc";
    vector<char> ds;
    vector<bool> vis(s.size(),false);
    perm(s,res,ds,vis);
    for(string x: res) {
    	cout<<x<<endl;
    }
    return 0;
}