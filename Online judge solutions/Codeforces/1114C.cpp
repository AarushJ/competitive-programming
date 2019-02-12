#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i, b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpp(i, a, b) for(ll i = ll(a); i<ll(b) ; i++) 

ll MOD = 1e9 + 7;

inline ll fmm(ll a,ll b,ll m=MOD) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}return r%m;}
inline ll fme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1){r*=a;r%=m;}a*=a;a%=m;b>>=1;}return r%m;}
inline ll sfme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}return r%m;}

ll n, b;

bool overflow(ll a, ll b){
	ll x = a*b;
	if( a != 0 && (x/a) != b ) return true;
	return false;
}

int main(){
	cin >> n >> b;
	map<ll,ll> pf;
	ll tmp = b;
	ll cnt = 0;
	while(tmp%2==0){
		cnt++;
		tmp/=2;
	}
	if(cnt > 0)	pf[2] = cnt;

	ll i = 3;
	while(tmp > 1 && i*i <= tmp){
		if( tmp%i == 0 ){
			cnt = 0;
			while(tmp%i == 0){
				cnt++;
				tmp/=i;
			}
			pf[i] = cnt;
		}
		i += 2;
	}
	if(tmp > 1) pf[tmp] = 1;
	
	ll minn = 1e18 + 2;
	for(auto it: pf){	// logn
		ll N = n;
		ll num = it.first;
		ll pwr = 0;
		while(N/num){
			pwr += N/num;
			ll initial_num = num;
			
			if( overflow(num, it.first) )	break;
			num*=it.first;
		}
 		ll cc = pwr;
 		ll bb = it.second;
 		ll div = cc/bb;
 		ll rem = cc - (cc/bb)*bb;

 		if( rem >= bb)	continue;

		minn = min(minn, pwr/it.second);
	}
	cout << minn << "\n";


}