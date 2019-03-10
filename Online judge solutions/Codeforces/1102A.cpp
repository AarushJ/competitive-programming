#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	if( n%2 == 0 ){
		if( (n/2)%2 == 0 ){
			cout << 0 << "\n";
		}else{
			cout << 1 << "\n";
		}
	}else{
		if( n ==  1 )	cout << 1 << "\n";
		else if ( n == 3 ) cout << 0 << "\n";
		else{
			ll a = n-1;
			if( ((n-1)/2)%2 == 0 ) cout  << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
}