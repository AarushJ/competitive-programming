#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 //Compiler version g++ 6.3.0

 int main(){
 	ll n;
 	cin >> n;
 	vector<ll> a(n);
 	for(ll i=0; i<n ; i++){
 		cin >> a[i];
 	}
 	ll req = ((n&1)?(n/2+1):(n/2));
 	for(ll d=-1000; d<=1000; d++){
 		if(d==0) continue;
 		ll cnt=0;
 		for(ll i=0; i<n; i++){
 			cnt = ((a[i]/d > 0)?(cnt+1):(cnt));
 		}
 		if(cnt >= req){
 			cout << d;
 			return 0;
 		}
 		
 	}
 	
     cout << 0;
 
 }	