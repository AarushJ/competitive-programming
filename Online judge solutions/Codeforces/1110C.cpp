#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i, b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpp(i, a, b) for(ll i = ll(a); i<ll(b) ; i++) 

ll q, a;

void solve(ll a){
	lpp(i, 1, 30){
		ll beg = 1<<(i-1), end = (1<<i)-1; 
		if( a >= beg && a <= end ){
			if( a != end ){
				cout << end << "\n";
				return;
			}else{
				ll maxx = 1;
				for(ll i = 2; i*i <= a ; i++){
					if( a%i == 0 ){
						ll num1 = i, num2 = a-i;
						maxx = max(maxx, __gcd(num1, num2));
						num1 = a/i; 
						num2 = a-num1;
						maxx = max(maxx, __gcd(num1, num2));
					}
				}
				cout << maxx << "\n";
				return;
			}
		} 
	}
}

int main(){
	cin >> q;
	lp(i, q){
		cin >> a;
		solve(a);
	}	
}

