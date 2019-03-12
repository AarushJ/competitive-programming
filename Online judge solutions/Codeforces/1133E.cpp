#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
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
vector<ll> a, teamSize;
ll dp[5005][5005];

int main(){
	cin >> n >> k;
	a.resize(n);
	teamSize.resize(n);
	lp(i, n)	cin >> a[i];
	sort(a.begin(), a.end());

	ll l = 0, r = 0;
	lp(i, n){
		while( r < n && a[r] - a[i] <= 5 )	r++;
		if( r >= i ) teamSize[i] = r-i;
	}

	// dp[i][j] = max team size amongst players 0...i, having at most j teams

	for(ll i = 0; i < n ; i++){
		for(ll j = 0 ; j <= k ; j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if( j + 1 <= k ) 
				dp[i+ teamSize[i]][j+1] = max(dp[i + teamSize[i]][j+1], dp[i][j] + teamSize[i]);
		}
	}

	cout << dp[n][k] << "\n";

}