#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
using namespace std;

typedef long long ll;
#define lp(i, b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpp(i, a, b) for(ll i = ll(a); i<ll(b) ; i++) 

const ll MOD = 1e9 + 7;

inline ll fmm(ll a,ll b,ll m=MOD) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}return r%m;}
inline ll fme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1){r*=a;r%=m;}a*=a;a%=m;b>>=1;}return r%m;}
inline ll sfme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}return r%m;}
inline ll char2digit(char ch){	return ch-'0';}

ll n, k;
vector<vector<ll>> g;
vector<bool> vis;

ll dfs(ll v){	
	vis[v] = 1;
	ll sum = 1;
	for(auto u: g[v]){
		if( !vis[u] ){
			sum += dfs(u);
		}
	}
	return sum;
}

int main(){
	cin >> n >> k;
	g.resize(n+1);
	vis.resize(n+1);

	lp(i, n-1){
		ll a, b, col;
		cin >> a >> b >> col;
		if( col )	continue;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	ll ans = fme(n, k);
	lpp(i, 1, n+1){
		if( !vis[i] ){
			ll component_size = dfs(i);
			ans = (ans - fme(component_size, k) + MOD)%MOD;
		}
	}
	
	cout << ans << "\n";
}