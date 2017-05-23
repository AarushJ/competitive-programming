/*
	AARUSH JUNEJA
	@vivace1
	TOPICS : goldbach's conjecture, number theory
*/

#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
bool isPrime(ll n){
    if(n==2) return true;
    if(n%2==0)  return false;
    int root = sqrt(n);
    for(int i=3 ; i<=root ; i+=2){
        if(n%i==0)  return false;
    }
    return true;
}

int main(){
    ll n;
    cin >> n;
    if(isPrime(n))  cout << 1;
    else if(n%2==0)  cout << 2;
    else if(isPrime(n-2))   cout << 2;
    else cout << 3;
    return 0;
}
