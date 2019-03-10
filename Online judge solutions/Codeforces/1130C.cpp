#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 //Compiler version g++ 6.3.0
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
ll n, r1, c1, r2, c2;
bool vis[55][55];
ll g[55][55], cmp[55][55];
ll curr = 0;
vector<vector<pair<ll,ll> > > component;
vector<pair<ll,ll> > comp;

bool ok(ll x, ll y){
	if(x>= 1 && y >= 1 && x <= n && y <= n)
	    return true;
	return false;
}

void dfs(ll x, ll y){
	if(vis[x][y]) return;
	cmp[x][y] = curr;
	comp.push_back({x, y});
	vis[x][y] = true;
	for(ll i = 0; i < 4; i++){
		ll xx = x + dx[i];
		ll yy = y + dy[i];
		if( ok(xx, yy) && (!vis[xx][yy]) && (!g[xx][yy])  ){
			dfs(xx, yy);
		}
	}
	
}

ll dist(ll a, ll b, ll c, ll d){
	ll ac = (a-c)*(a-c);
	ll bd = (b-d)*(b-d);
	return ac + bd;
}

 int main(){
 	cin >> n >> r1 >> c1 >> r2 >> c2;
 	ll num;
 	for(ll i=1; i<=n ; i++){
 		string str;
 		cin >> str;
 		for(ll j=1; j<=n ; j++){
 		    g[i][j] = str[j-1]-'0';
 	    }
 	}
 	
 	for(ll i=1; i<=n ; i++){
 		for(ll j=1; j<=n ; j++){
 		    if(!g[i][j] && !vis[i][j]){
     			dfs(i, j);
     			component.push_back(comp);
     			curr++;
     			comp.clear();
     		}
 	    }
 	}
 	
 	
 	ll source = cmp[r1][c1], target = cmp[r2][c2];
 	ll ans = 0;
 	if( source == target ){
 		ans = 0;
 	}else{
 		ans = 1e6;
 		ll sz = component[source].size();
 		ll tz = component[target].size();
 		for(ll i = 0; i < sz ; i++){
 			for(ll j = 0; j < tz ; j++){
 				ll a = component[source][i].first;
 				ll b = component[source][i].second;
 				ll c = component[target][j].first;
 				ll d = component[target][j].second;
 				ans = min(ans, dist(a, b, c, d));
 			}
 		}
 	}
 	cout << ans << "\n";
 }	