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

ll n, k;
vector<ll> d;
vector<ll> candies;


int main(){
	cin >> n >> k;
	d.resize(n);
	candies.resize(k);
	lp(i, n){
		cin >> d[i];
		candies[d[i]%k]++;
	}	
	ll ans = 0;
	ans += 2*(candies[0]/2);

	for(ll i = 1 ; i< k/2 ; i++){
		if(candies[i] && candies[k-i] ){
			ll a = candies[i], b = candies[k-i];
			ans += (min(a, b)*2);
		}
	}

	if(k%2 && k > 1){
		ll a = k/2, b = k - k/2;
		if( candies[a] && candies[b] ){
			a = candies[a], b = candies[b];
			ans += min(a, b)*2;
		}
	}else if(k > 1){
		if( candies[k/2] )	ans += 2*(candies[k/2]/2);
	}
	cout << ans << "\n";
}