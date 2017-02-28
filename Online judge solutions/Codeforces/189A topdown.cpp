#include<bits/stdc++.h>
using namespace std;

#define MAX 1e6
#define MOD 1e7

typedef double lf;
typedef long long ll;
typedef long double LF;
typedef unsigned long long ull;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef map<string,ll> msl;
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
#define f first
#define s second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,a,b) for(ll i = ll(a); i<ll(b) ; i++) 
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)

ll ip(){
	ll x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc()); x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}

inline ll ncr(ll n,ll r){ ll ans = 1 ; if(r > n-r) r = n-r; lp(i,0,r){ans*=(n-i) ; ans/=(i+1); } rtn ans; }
inline ll gcd(ll a,ll b){if(!a) rtn b; rtn gcd(b%a,a); }
inline ll fme(ll x,ll n,ll mod){ll ans=1;x%=mod;while(n>0){if(n&1){ ans*=x;ans%=mod;} x*=x;x%=mod;n>>=1;}rtn ans%mod;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,0,(len/2)+1){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)%gcd(a,b); }
inline ll fmm(ll a,ll b,ll m) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}rtn r%m;}
inline ll sfme(ll a,ll b,ll m) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}rtn r%m;}
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

ll f(ll dp[],ll a[],ll i){
    if(i<0) return LLONG_MIN;
    if(dp[i]!=-1)   return dp[i];
    ll temp = max(max(f(dp,a,i-a[2]),f(dp,a,i-a[1])),f(dp,a,i-a[0]));
    if(temp < -1){
        dp[i] = LLONG_MIN;
    }else{
        dp[i] = temp+1;
    }
    return dp[i];
}

int main(){
	ios::sync_with_stdio(false);
	ll n,a[3];
	cin >> n >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	ll dp[n+1];
	dp[0] = 0;
	lp(i,1,n+1) dp[i] = -1;

	cout << f(dp,a,n) << "\n";
	return 0;
}
