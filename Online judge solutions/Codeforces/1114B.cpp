#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i, b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpp(i, a, b) for(ll i = ll(a); i<ll(b) ; i++) 

ll MOD = 1e9 + 7;

inline ll fmm(ll a,ll b,ll m=MOD) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}return r%m;}
inline ll fme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1){r*=a;r%=m;}a*=a;a%=m;b>>=1;}return r%m;}
inline ll sfme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}return r%m;}

ll n, m, k;
vector<ll> a;

int main(){
	cin >> n >> m >> k;
	a.resize(n);
	lp(i, n)	cin >> a[i];

	vector<pair<ll,ll> > tmp;
	lp(i, n){
		tmp.push_back({a[i], i+1});
	}

	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());

	ll sum = 0;
	lp(i, m*k)	sum += tmp[i].first;

	map<ll,ll> mp;
	lp(i, m*k)	mp[tmp[i].first]++;		
	
	vector<ll> ans;
	
	ll index = 0;
	lp(i, k){
		ll left = m;
		for(; index < n && left > 0; index++){
			if(mp[a[index]]){
				mp[a[index]]--;
				left--;
				if(left == 0){
					if( i != k-1 )	ans.push_back(index+1);
				}
			}
		}
	}

	cout << sum << "\n";
	for(auto it: ans)	cout << it << " ";
	cout << "\n";


}