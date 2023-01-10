/*
    reverse an array recursively using pseudo 2 pointer
    i, n-i-1 be indices
    T.c = O(n), N/2
    s.c = O(n), N/2 stack depth
*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i=0) {
    if (i >= s.size()/2) return true;
    if (s[i] != s[s.size() - i - 1]) return false;
    return isPalindrome(s,i+1);
} 

int main()
{
    string s ="malayalam";
    if (isPalindrome(s)) cout<<s<<" is Palindrome";
    else cout<<s<<" is not a Palindrome";
    cout<<'\n';
    return 0;
}