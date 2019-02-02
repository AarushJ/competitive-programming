#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 

int main(){
	ll n, m;
	cin >> n >> m;
	vector<ll> g[n+1];
	lp(i, m){
		ll a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	priority_queue<ll, vector<ll>, greater<ll> > pq;
	pq.push(1);
	vector<ll> ans;
	vector<bool> vis(n+1, false);
	vis[1] = 1;

	vector<bool> added(n+1, false);

	while(!pq.empty()){
		ll curr = pq.top();
		pq.pop();
		if( !added[curr] ){
			ans.push_back(curr);
			added[curr] = 1;	
		}
		for(vector<ll>::iterator it = g[curr].begin() ; it!= g[curr].end(); it++){
			ll u = curr, v = *it;
			if( !vis[v] ){
				pq.push(v);
				vis[v] = 1;
			}
		}
	}

	lp(i, n)	cout << ans[i] << " "; cout << "\n";

}