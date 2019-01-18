#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll mod = 1000000007;
 
int main(){
	ll t;
	cin >> t;
	while( t-- ){
		string str;
		cin >> str;
		ll n = str.size();
		ll dp[n + 1];
		vector<ll> ext(26);
 
		dp[0] = 1;
 
		for(ll i = 1 ; i <=  n ; i++){
			ll pos = str[i - 1] - 'A';
			dp[i] = (2*dp[i - 1])%mod ;
			dp[i] = (dp[i] - ext[pos] + mod)%mod;
			ext[pos] = dp[i-1];
		}
 
		cout << dp[n] << "\n";
	}
	return 0;
}