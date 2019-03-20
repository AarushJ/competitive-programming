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

ll n;
vector<ll> a;
map<ll,vector<pair<ll,ll> > > mp;

int main(){
	cin >> n;
	a.resize(n);
	lp(i, n)	cin >> a[i];
	
	lp(i, n){
		ll sum = 0;
		lpp(j, i, n){
			sum += a[j];
			mp[sum].push_back({i, j});
		}
	}

	for(auto it: mp){
		ll key = it.first;
		sort(mp[key].begin(), mp[key].end(), [](pair<ll,ll> a, pair<ll,ll> b){ return a.second < b.second;});
	}

	ll ans = 0;
	vector<pair<ll,ll> > ans_blocks;
	for(auto it: mp){
		ll len = 0;
		ll sum = it.first;
		ll previous_end = -1;
		vector<pair<ll,ll> > blocks = it.second;
		vector<pair<ll,ll> > curr_blocks;
		
		for(auto block: blocks){
			if( block.first > previous_end ){
				len++;
				curr_blocks.push_back(block);
				previous_end = block.second;
			}
		}
		if( len > ans ){
			ans = len;
			ans_blocks = curr_blocks;
		}
	}

	cout << ans << "\n";
	for(auto block: ans_blocks){
		cout << block.first + 1 << " " << block.second + 1 << "\n";
	}


}