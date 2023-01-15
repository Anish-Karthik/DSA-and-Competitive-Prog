#include<bits/stdc++.h>
using namespace std;
/*
	T.C = O(n^n * n)
	S.C = O(n)
*/
void perm(string &s, vector<string> &res, vector<char> &ds ) {
	//O(n) to copy a char vector to string,
	//O(n) to append string to res
	//O(n+n) = O(n)
	if (ds.size()==s.size()) {
		string tmp(s.size(),'1');
		for(int i =0; i<s.size();i++) tmp[i] = ds[i];
		res.push_back(tmp);
		return;
	}

	for(int i = 0;i<s.size();i++) {
		ds.push_back(s[i]);
		perm(s,res,ds); 
		ds.pop_back();
	}

}

int main()
{
    vector<string> res;
    string s = "abcdefg";
    vector<char> ds;
    perm(s,res,ds);
    for(string x: res) {
    	cout<<x<<endl;
    }
    return 0;
}