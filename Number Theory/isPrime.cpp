#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n==2 || n==3) {
        return true;
    }
    if (n<=1 || n%2==0 || n%3==0) {
        return false;
    }
    for (int i = 5; i*i <= n;i+=6) {
        if (n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
	cout<<"Enter a number: ";
    cin>>n;
    if (isPrime(n)) {
        cout<<n<<" is a prime number"<<endl;
    } else {
        cout<<n<<" is not a prime number"<<endl;
    }
	return 0;
}
