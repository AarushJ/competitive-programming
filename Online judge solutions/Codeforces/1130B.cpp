#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 //Compiler version g++ 6.3.0

 int main(){
 	ll n;
 	cin >> n;
 	ll num;
 	vector<pair<ll,bool> > v[n+1];
 	for(ll i=0; i<2*n ; i++){
 		cin >> num;
 		v[num].push_back(make_pair(i, 0));
 	}
 	
 	ll ans = 0, prev = 0;
 	for(ll i=1; i<=n; i++){
 		pair<ll,bool> p = v[i][0], q = v[i][1];
 		ll idx = ((p.first < q.first)?(0):(1));
 		ans += abs(v[i][idx].first - prev);
 		v[i][idx].second = 1;
 		prev = v[i][idx].first;
 	}
 	
 	prev = 0;
 	for(ll i=1; i<=n; i++){
 		pair<ll,bool> p = v[i][0], q = v[i][1];
 		if(p.second == false){
 		   ans += abs(p.first-prev);
 		   prev = p.first;
 		}else{
 		   ans += abs(q.first-prev);
 		   prev = q.first;
 		}
 	}
 	
     cout << ans;
 
 }	