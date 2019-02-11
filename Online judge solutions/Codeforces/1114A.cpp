#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i, b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpp(i, a, b) for(ll i = ll(a); i<ll(b) ; i++) 

ll MOD = 1e9 + 7;

inline ll fmm(ll a,ll b,ll m=MOD) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}return r%m;}
inline ll fme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1){r*=a;r%=m;}a*=a;a%=m;b>>=1;}return r%m;}
inline ll sfme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}return r%m;}

int main(){
	ll a, b, c, green, purple, black;
	cin >> a >> b >> c >> green >> purple >> black;
	if( green < a ){
		cout << "NO\n";
		return 0;
	}	
	green -= a;
	if( green + purple < b ){
		cout << "NO\n";
		return 0;
	}
	ll left = green + purple;
	left -= b;
	if( left + black < c ){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}