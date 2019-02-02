#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,b) for(ll i = ll(0); i<=ll(b) ; i++) 

int main(){
	ll n, t, k;
	cin >> n;
	char m[n][n];
	char cross =	'X';
	lp(i, n-1){
		lp(j, n - 1){
			cin >> m[i][j];
		}
	}
	ll ans = 0;
	for(int i = 1 ; i < n - 1 ; i++){
		for(int j = 1 ; j < n - 1 ; j++){
			if( m[i][j] == cross && m[i-1][j-1] == cross && m[i-1][j+1] == cross && m[i+1][j-1] == cross && m[i+1][j+1] == cross){
				ans++;
			}
		}
	}
	cout << ans << "\n";

}