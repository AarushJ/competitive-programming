/*
	user : vivace
	topic : Fenwick tree based question. Knowledge about working of Fenwick tree required but code of fenwick tree not required.
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,a)	for(ll i = (ll)0 ; i < ll(a) ; i++)

pair<ll,ll> cnt(string &str){
	ll size = (ll)(str.length());
	ll ones = 0, suff = 0;
	bool flag = true;
	for(ll i = size-1 ; i>=0 ; i--){
		if( str[i] == '1' ){
			ones++;
			if( flag )	suff++;
		}else{
			flag = false;
		}
	}
	return make_pair(ones,suff);
}

int main(){
	ll t,n; 
	string str1,str2,str3;
	cin >> t;
	lp(i,t){
		cin >> str1 >> str2 >> str3 >> n;
		pair<ll,ll> cnt1 = cnt(str1), cnt2 = cnt(str2), cnt3 = cnt(str3);
		ll ans = cnt1.first + n*cnt2.first + cnt3.first;
		if( cnt3.second < str3.length() )	ans -= cnt3.second;
		else if( cnt2.second < str2.length() )	ans -= (cnt3.first + cnt2.second);
		else ans -= (cnt3.first + n*cnt2.first + cnt1.second);
		
		ans++; 	// for first lookup to BIT
		cout << ans << "\n";
	}
	return 0;
}