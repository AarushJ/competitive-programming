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
vector<ll> a, b;
map<pair<pair<ll,ll>, bool>, ll> mp;

int main(){
	cin >> n;
	a.resize(n);
	b.resize(n);

	lp(i, n)	cin >> a[i];
	lp(i, n)	cin >> b[i];

	ll ans = 0;
	ll d0 = 0, dont_care = 0;

	lp(i, n){
		bool neg = false;
		if( a[i] == 0 ){
			if( b[i] == 0 ){
				dont_care++;
			}
			continue;
		}
		if( b[i] == 0 ){
			d0++;
			continue;
		}	

		if( (a[i] < 0 && b[i] > 0) || (a[i] > 0 && b[i] < 0) )	neg = true;

		a[i] = abs(a[i]);
		b[i] = abs(b[i]);

		ll gcd = __gcd(a[i], b[i]);
		a[i] /= gcd;
		b[i] /= gcd;
		pair<pair<ll,ll>, bool> p = {{a[i], b[i]}, neg};
		mp[p]++;
		ans = max(ans, mp[p]);
	}	

	ans = max(ans, d0);
	cout << ans + dont_care << "\n";

}