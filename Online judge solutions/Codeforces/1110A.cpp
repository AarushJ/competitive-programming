#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 

ll b, k, a;

int main(){
	cin >> b >> k;
	ll parity = 0;
	lp(i, k-1){
		cin >> a;
		parity = (parity + (a%2)*(b%2))%2;
	}
	cin >> a;
	parity = (parity + a%2)%2;
	if( parity )	cout << "odd\n";
	else cout << "even\n";
}



