#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n, x, y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	for(ll i = 0 ; i < n ; i++)	cin >> a[i];
	if( x > y ){
		cout << n << "\n";
		return 0;
	}	

	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		if( a[i] <= x )	cnt++;
	}

	if( cnt%2 == 0 )	cout << cnt / 2 << "\n";
	else cout << (cnt+1)/2 << "\n";
	
}