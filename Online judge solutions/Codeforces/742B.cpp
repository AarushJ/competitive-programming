/*
	AARUSH JUNEJA
	@vivace
	TOPICS : STL
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,a,b) for(ll i = ll(a); i<ll(b) ; i++)


int main(){
	ll n,x,ans = 0;
	cin >> n >> x;
	map<ll,ll> m;
	ll arr[n];
	lp(i,0,n){
		cin >> arr[i];
		map<ll,ll>::iterator it = m.find(arr[i]^x);
		if(it!=m.end()){
			ans += it->second;
		}
		m[arr[i]] = m[arr[i]]+1;
	}
	cout << ans << "\n";	
}
