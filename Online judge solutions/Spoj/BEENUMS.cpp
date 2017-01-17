#include <iostream>
#include <set>
#define MAX 1000000000
using namespace std;
typedef long long ll;

int main() {
	ll i=1 ; 
	set<ll> s;
	ll t=1;
	while(t <= MAX){
		s.insert(t);
		i++;
		t = 3*i*i - 3*i + 1;
	}
	// your code goes here
	ll n;
	while(1){
		scanf("%lld",&n);
		if(n==-1) break;
		else{
			if(s.find(n)!=s.end()){
				cout << "Y\n";
			}else{
				cout <<"N\n";
			}
		}
	}
	return 0;
}
