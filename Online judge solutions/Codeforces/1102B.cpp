#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll i = 0 ; i < n ; i++)	cin >> a[i];
	map<ll, vector<ll> > indices;
	for(ll i = 0 ; i < n ; i++)	indices[a[i]].push_back(i);
	for(auto it: indices){
		if( it.second.size() > k ){
			cout << "NO\n";
			return 0;
		}	
	}

    // color with 1 color first
    vector<ll> ans(n);
    map<ll,ll> given;
    for(auto it: indices){
        vector<ll> locs = it.second;
        
    }

	ll col = 1;
	for(auto it: indices){
		vector<ll> locs = it.second;
		for(auto jt: locs){
			ans[jt] = col;
			col = (col + 1)%(k+1);
			if( col == 0 )  col = 1;
		}
	}
	cout << "YES\n";
	for(auto it: ans)	cout << it << " ";
	cout << "\n";
}