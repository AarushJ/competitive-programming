#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 

struct node{
	ll index;
	ll cost;
	ll rem;
	ll type; 
};

bool cmp(node &a, node &b){
	if( a.cost == b.cost )	return a.index < b.index;
	return a.cost < b.cost;
}

int main(){
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), c(n);
	vector<node> v(n);
	lp(i, n)	cin >> a[i];
	lp(i, n) 	cin >> c[i];

	lp(i, n){
		v[i].rem = a[i];
		v[i].type = i+1;
		v[i].cost = c[i];
		v[i].index = i;
	}

	map<ll,ll> revMap;
	

	sort(v.begin(), v.end(), cmp);
	
	
	lp(i, n){
		revMap[v[i].type] = i;
	}

	

	ll index = 0;
	while(m--){
		ll type, cnt;
		cin >> type >> cnt;
		ll pos = revMap[type];
		if( v[pos].rem >= cnt ){
			v[pos].rem -= cnt;
			cout << cnt*v[pos].cost << "\n";
		}else{
			ll left = cnt;
			ll ans = 0;
			if( v[pos].rem ){
				left -= v[pos].rem;
				ans = v[pos].rem*v[pos].cost;
				v[pos].rem = 0;
			}
			while(index < n && left != 0){
				if( v[index].rem > left ){
					ans += (left*v[index].cost);
					v[index].rem -= left;
					left = 0;
				}else if( v[index].rem == left ){
					ans += (left*v[index].cost);
					v[index].rem = 0;
					left = 0;
					index++;
				}else{
					ans += (v[index].rem*v[index].cost);
					left -= v[index].rem;
					v[index].rem = 0;
					index++;
				}
			}
			if( left != 0 && index >= n )	cout << 0 << "\n";
			else cout << ans << "\n";	
		}

	}


}