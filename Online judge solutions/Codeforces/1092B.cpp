#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i = 0 ; i < n ; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	ll minn = 0;
	for(ll i = 1 ; i < n ; i+=2){
		minn += (a[i] - a[i - 1]);
	}

	ll sum = 0;
	for(ll i = n - 1 ; i > 0 ; i-=2){
		sum += (a[i] - a[i - 1]);
	}
	cout << min(minn, sum) << "\n";
}