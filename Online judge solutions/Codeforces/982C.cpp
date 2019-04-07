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

int n;
vector<vector<int>> g; 
vector<int> sub;
int cnt = 0;

void dfs(int node, int par){
	for(auto u: g[node]){
		if( u != par ){
			dfs(u, node);
			if( sub[u]&1 ){
				sub[node] += sub[u];	
			}else{
				cnt++;
			}
		}
	}
}

int main(){
	cin >> n;
	g.resize(n+1);
	sub.resize(n+1, 1);


	lp(i, n-1){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	if( n&1 ){
		cout << -1 << "\n";
		return 0;
	}

	dfs(1, -1);
	
	cout << cnt << "\n";

}