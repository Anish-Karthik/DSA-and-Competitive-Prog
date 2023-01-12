#include<bits/stdc++.h>
using namespace std;
void perm(string &s, vector<string> &res,int ind=0) {

	if (ind==s.size()) {
		res.push_back(s);
		return;
	}

	for(int i =ind;i<s.size();i++) {
		swap(s[i],s[ind]);
		perm(s,res,ind+1);
		swap(s[i],s[ind]);
	}

}


int main()
{
    vector<string> res;
    string s = "abc";
    perm(s,res,0);
    for(string x: res) {
    	cout<<x<<endl;
    }
    return 0;
}