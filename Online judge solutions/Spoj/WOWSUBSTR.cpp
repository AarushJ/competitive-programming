#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,b) for(ll i = ll(0); i < ll(b) ; i++) 
#define lpp(i, a, b)	for(ll i = (ll)a ; i <= (ll)b ; i++)
#define mod 100007

inline ll fme(ll x,ll n){ll ans=1;x%=mod;while(n>0){if(n&1){ ans*=x;ans%=mod;} x*=x;x%=mod;n>>=1;} return ans%mod;}

ll add(ll a, ll b){
	a += b;
	if(a >= mod)
		a -= mod;
	return a;
}

ll mul(ll a, ll b){
	if( a >= mod ) a %= mod;
	if( b >= mod ) b %= mod;
	return (a * b) % mod;
}

ll res(ll n){
	ll sum = 0;
	sum = (n*(n+1)*(n+2))/6;
	return sum % mod;
}

ll res1(ll n){
	ll sum = 0;
	sum = (n*(n+1))>>1;
	return sum % mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t, len;
	string str;	// str contains only small letters
	cin >> t;
	ll tt = 1;
	while(t--){
		cin >> str;
		len = str.length();
		int last[26];	// last occurence of str[i]-'a'
		lp(i, 26)	last[i] = -1;

		last[str[0]-'a'] = 0;
		int beganAt = 0, curr_sub = 1;
		ll ans = 0;
		for(int i = 1 ; i<len ; i++){
			
			int prev = last[str[i]-'a'];
			
			// not part of curr_sub
			if( prev == -1 || prev < beganAt ){
				last[str[i]-'a'] = i;
				curr_sub++;
			}else{
				last[str[i]-'a'] = i;
				ll a = prev-beganAt+1;
				ll b = i-1-prev;
				ans = add(ans, res(a));
				ans = add(ans, mul(a, res1(b)));
				ans = add(ans, mul(b, res1(a)));
				beganAt = prev+1;
				curr_sub = i - prev;
			}
			if( i == len -1 ){
					ans = add(ans, res(curr_sub));
			}
		}

		cout << "Case " << tt++ << ": " <<  ans << "\n";
	}
	return 0;
}