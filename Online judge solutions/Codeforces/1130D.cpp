#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 //Compiler version g++ 
 	
 ll n, m;
 
 ll dist(ll a, ll b){
 	if(b >= a)	return b-a;
 	return b-a+n;
 }
 
 int main(){
 	cin >> n >> m;
 	vector<ll> last(n+1, n+10), freq(n+1);
 	for(ll i = 0; i < m ; i++){
 		ll a, b;
 		cin >> a >> b;
 		freq[a]++;
 		last[a] = min(last[a], dist(a, b));
 	}
 	
 	for(ll beg = 1; beg <= n ; beg++){
 		ll ans = -1;
 		for(ll i = 1; i <= n ; i++){
 			if(freq[i] == 0) continue;
 			ll curr = dist(beg, i);
 			curr += (n * (freq[i] - 1));
 			curr += last[i];
 			ans = max(ans, curr);;
 		}
 		cout << ans << " ";
 	}
 	
 	cout << "\n";
 }	