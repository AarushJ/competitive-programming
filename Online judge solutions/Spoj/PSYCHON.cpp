/*
	AARUSH JUNEJA
	@vivace
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 100010

typedef double lf;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef map<string,ll> msl;
typedef pair<int,int> pii;
typedef pair<ll,ll> ii;
typedef vector<ii > vpll;
typedef map<ll,ll> mll;
typedef vector<vll > matrix;
typedef list<ll> lll;
typedef vector<lll > vlll;
typedef pair<ll,ii> iii;

#define rtn return 
#define gc getchar
#define pb push_back
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)
#define min3(a,b,c)	min(a,min(b,c))
#define max3(a,b,c)	max(a,max(b,c))

//////////////////////////////////////////// CONTAINERS FOR FUNCTIONS MENTIONED IN TEMPLATE ///////////////////////////////////
#define MAX 10000005
int spf[MAX];
//////////////////////////////////////////// FUNCTIONS THAT NEED COMMENTED OUT CONTAINERS ////////////////////////////////////
void spf_sieve(){	for(int i=2 ; i<MAX ; i++){ if(i&1) spf[i] = i; else spf[i] = 2;}	
	for(ll i=3 ; i<MAX ; i+=2){	if(spf[i]==i){  for(ll j=i*i ; j<=MAX ; j+=i){ if(spf[j]==j) spf[j] = i; } } }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,m,e,a,b,q,h,f,w,x,y,k,p;
    ///////////// START FROM HERE ////////////////////
    spf_sieve();
	cin >> t;
	while(t--){
		cin >> n;
		map<int,int> mp;
		while(n > 1){
			mp[spf[n]]++;
			n /= spf[n];
		}
		int even = 0, odd  = 0;
		lpit(it,mp){
			if( it->ss & 1 )	odd++;
			else even++;
		}	
		cout << (( even > odd ) ? "Psycho Number" : "Ordinary Number") << "\n";
	}    
	
	
			
	return 0;
}
