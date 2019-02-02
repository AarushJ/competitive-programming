#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 



int main(){
	ll n, m;
	cin >> n;
	vector<ll> a(n);
	lp(i, n)	cin >> a[i];
	sort(a.begin(), a.end());
	ll l = 0, r = n - 1;
	ll ans = 0;
	while(l < r){
		ans += (a[l] + a[r])*(a[l] + a[r]);
		l++;
		r--;
	}
	cout << ans << "\n";

}