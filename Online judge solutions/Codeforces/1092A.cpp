#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n, k, t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		string str = "";
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < k ; j++){
				str.push_back('a' + j);
				if( str.length() == n )	break;
			}
 			if( str.length() == n )	break;
 		}
		cout << str << "\n";
	}


}