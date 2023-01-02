#include <bits/stdc++.h>
using namespace std;

bool prime[10000001];
void computeAllPrime(int s=2,int n =10000001) {
    int p = 1000001;
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i*i<=n ; i++) {
        if (prime[i]) {
            for (int j = i*i; j<=n; j+=i) {
                prime[j] = false;
            }
        }
    }
    for (int i = s; i<=n ; i++) {
        if (prime[i]) {
            cout<<i<<", ";
        }
    }
    cout<<'\n';
}
int main() {
    int l,h;
	cout<<"Enter a number range: ";
    cin>>l>>h;
    cout<< "All the the prime numbers in a given range of "<<l<<" - "<<h<<" are:\n";
    computeAllPrime(l,h);
	return 0;
}

