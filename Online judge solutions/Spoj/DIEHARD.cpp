/*
	AARUSH JUNEJA
	@vivace
	IIT(ISM),Dhanbad
*/

#include<bits/stdc++.h>
using namespace std;

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
typedef vector<vll > vvll;
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

ll ip(){
	ll x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc()); x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}
//////////////////////////////////////////// CONTAINERS FOR FUNCTIONS MENTIONED IN TEMPLATE ///////////////////////////////////
#define MAX 100005
//bool isPrime[MAX];
//int spf[MAX];
//////////////////////////////////////////// FUNCTIONS THAT NEED COMMENTED OUT CONTAINERS ////////////////////////////////////


//void prime_sieve(){ for(ll i=2 ; i*i<=MAX ; i++){	if(!isPrime[i]){ for(ll j=i*i ; j<=MAX ; j+=i)	isPrime[j] = 1;} } 	}
//void spf_sieve(){	for(ll i=2 ; i<MAX ; i+=2)	spf[i] = 2;
//	for(ll i=3 ; i<MAX ; i+=2){	if(!isPrime[i]){ spf[i] = i; for(ll j=i ; (j*i)<MAX ; j+=2){ if(!isPrime[i*j])	isPrime[i*j] = true , spf[i*j] = i; } } }
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline ll ncr(ll n,ll r){ ll ans = 1 ; if(r > n-r) r = n-r; lp(i,r+1){ans*=(n-i) ; ans/=(i+1); } rtn ans; }
inline ll gcd(ll a,ll b){if(!a) rtn b; rtn gcd(b%a,a); }
inline ll fme(ll x,ll n,ll mod){ll ans=1;x%=mod;while(n>0){if(n&1){ ans*=x;ans%=mod;} x*=x;x%=mod;n>>=1;}rtn ans%mod;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,(len/2)+2){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b,ll m) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}rtn r%m;}
inline ll sfme(ll a,ll b,ll m) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}rtn r%m;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

#define MOD 1000000007
#define N 100010

ll dp[2005][2005];

void init(ll h, ll a){
	lp(i,2005){
		lp(j,2005){
			dp[i][j] = -1;
		}
	}
}

// states : 1-> air, 2->water, 3->fire

ll f(ll h, ll a, ll time, ll state){
	if(h <=0 || a<=0)	return time-1;
	if(dp[h][a]!=-1)	return dp[h][a];
	
	if(state!=1)	return dp[h][a] = f(h+3,a+2,time+1,1);
	
	return dp[h][a] = max(f(h-5,a-10,time+1,2),f(h-20,a+5,time+1,3));
	
	
}

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,h,a,b,q,w,k;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////

	cin >> t;
	while(t--){
		cin >> h >> a;
		init(h,a);
		cout << f(h,a,0,0) << "\n"; // false state to make next state as air
	}
	
	
	
	return 0;
}
