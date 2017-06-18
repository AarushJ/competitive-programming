/*
	TOPICS : Binary search on the answer, strings
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
#define min3(a,b,c)	min(a,min(b,c))
#define max3(a,b,c)	max(a,max(b,c))

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
inline ll fme(ll x,ll n){ll ans=1;x%=MOD;while(n>0){if(n&1){ ans*=x;ans%=MOD;} x*=x;x%=MOD;n>>=1;}rtn ans%MOD;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,(len/2)+2){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b) {ll r=0;a%=MOD;b%=MOD;while(b>0){if(b&1){r+=a;r%=MOD;}a+=a;a%=MOD;b>>=1;}rtn r%MOD;}
inline ll sfme(ll a,ll b) {ll r=1;a%=MOD;while(b>0){if(b&1)r=fmm(r,a);a=fmm(a,a);b>>=1;}rtn r%MOD;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

bool possible(vector<ll> &block, ll k, ll x){
	ll size = block.size();
	ll flips = 0;
	lp(i, size){
		if( block[i] > x )flips += (block[i])/(x+1);
		if( flips > k )	return false;
	}
	return true;
}

bool solveEdgeCase(string &str, ll k){
	ll size = str.size();	
	ll cnt1 = 0, cnt2 = 0;	// cnt1 => 1010...; cnt2 => 0101...
	lp(i, size){
		if(i&1){
			if( str[i] == '1' )	cnt1++;
			else cnt2++;
		}else{
			if( str[i] == '1' )	cnt2++;
			else cnt1++;
		}
	}
	return ( min(cnt1, cnt2) <= k );
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,k,q,a,b,c,d,e,f,g,h,s,p;	
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		string str;
		cin >> str;
		bool flag = solveEdgeCase(str, k);	// ans => 1
		if( flag ){
			cout << 1 << "\n";
			continue;
		}
		vll block;
		ll i = 0;
		while( i < n ){
			if( str[i] == '0' ){
				ll cnt = 0;
				while( str[i] == '0' ){
					cnt++; i++;
				}
				block.pb(cnt);
			}else{
				ll cnt = 0;
				while( str[i] == '1' ){
					cnt++; i++;
				}
				block.pb(cnt);
			}
		}
		ll lo = 2, hi = n;
		while( hi - lo > 1 ){
			ll mid = (lo+hi)>>1;
			if( possible(block, k , mid) ){
				hi = mid;
			}else{
				lo = mid;
			}
		} 
		if( !possible(block, k , lo) )	cout << lo+1 << "\n";
		else cout << lo << "\n";
	}

	return 0;
}































