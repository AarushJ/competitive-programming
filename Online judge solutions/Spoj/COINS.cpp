#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

map<ll,ll> maxCoins;


ll coins(ll n){
	if(maxCoins.find(n)!=maxCoins.end()){
		return maxCoins[n];
	}else{
		maxCoins[n] = max(coins(n/2)+coins(n/3)+coins(n/4),n);
	}
	return maxCoins[n];
}

int main(){
	ll n;
	while(cin >> n){
		maxCoins[0] = 0;
		cout << coins(n) << "\n";
	}
	return 0;
}
