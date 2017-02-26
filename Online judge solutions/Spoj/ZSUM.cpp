#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define MOD 10000007
ll fast_expo(ll x,ll y){
    ll res = 1;      
    x = x%MOD;  
              
    while(y > 0){
        if (y & 1)
            res = (res*x)%MOD;
 
        y = y>>1; 
        x = (x*x)%MOD;  
    }
    return res;
}

int main(){ 
	ll n,k;
	while(1){
		cin >> n >> k;
		if(n==0 && k==0)	break;
		ll ans = (fast_expo(n,k) + fast_expo(n,n) + (2*fast_expo(n-1,k))%MOD + (2*fast_expo(n-1,n-1))%MOD )%MOD ;
		cout << ans <<"\n";
	}
	return 0;
}
