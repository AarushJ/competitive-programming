#include<set>
#include<map>
#include<utility>
#include<cmath>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

typedef double lf;
typedef long long ll;
typedef long double LF;
typedef unsigned long long ull;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef map<string,ll> msl;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef map<ll,ll> mll;

#define loop(i,a,b) for(int i = int(a); i<=int(b) ; i++) 
#define itvll(c,it) for(vll::iterator it = c.begin() ; it!=c.end() ; it++)
#define itmll(c,it) for(mll::iterator it = c.begin() ; it!=c.end() ; it++)
#define itmsl(c,it) for(msl::iterator it = c.begin() ; it!=c.end() ; it++)

ll ncr(int n,int r){ ll ans = 1 ; if(r > n-r) r = n-r; for(int i=0 ; i<r ; i++){ans*=(n-i) ; ans/=(i+1); } return ans; }
ll gcd(ll a,ll b){if(!a) return b; return gcd(b%a,a); }

int main(){
	ll t,a,b,c;
	cin >> t;
	for(ll i=1 ; i<=t ; ++i){
		cin >> a >> b >> c;
		cout << "Case " << i << ": ";
		if(c%gcd(a,b)) 	cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
