#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i, b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpp(i, a, b) for(ll i = ll(a); i<ll(b) ; i++) 

ll MOD = 1e9 + 7;

inline ll fmm(ll a,ll b,ll m=MOD) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}return r%m;}
inline ll fme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1){r*=a;r%=m;}a*=a;a%=m;b>>=1;}return r%m;}
inline ll sfme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}return r%m;}
inline ll char2digit(char ch){	return ch-'0';}

ll n;
vector<ll> a;

int main(){
	cin >> n;
	a.resize(n);
	lp(i, n)	cin >> a[i];
	sort(a.begin(), a.end());

	ll	i = 0, ans = 0;
	for(auto it: a){
		ll beg = it;
		ll end = it+5;
		auto iter = upper_bound(a.begin() + i, a.end(), end);
		iter--;
		ll pos = iter - a.begin();

		ans = max(ans, pos - i + 1);
		i++;
	}
	cout << ans << "\n";
}