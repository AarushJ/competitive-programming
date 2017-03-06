/*
	AARUSH JUNEJA
	@vivace
	IIT(ISM),Dhanbad
*/

#include<bits/stdc++.h>
using namespace std;

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
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,a,b) for(ll i = ll(a); i<=ll(b) ; i++) 
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
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b,ll m) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}rtn r%m;}
inline ll sfme(ll a,ll b,ll m) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}rtn r%m;}
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//
#define N 70000


#define MOD 1000000007
#define EPS 0.0000000001
typedef long double ld;
ld p[N],v[N];
ld check(ld x,ll n){
	ld res = -1;
	lp(i,0,n-1)	res = max(res,fabs(x-p[i])/(v[i]*1.0));
	//cout << "returning : " << res << "\n";	
	return res;
}

int main(){
	//ios::sync_with_stdio(false);
	ll t,n,m,e,a,b,l,r,k;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
    cin >> n;
    
    lp(i,0,n-1)	cin >> p[i];
    lp(i,0,n-1) cin >> v[i];
	
	ld minn = INT_MAX,maxx = -1;
	
	lp(i,0,n-1){
		minn = min(minn,p[i]);
		maxx = max(maxx,p[i]);
	}
	    
	//cout << minn << "   " << maxx << "\n";
	    
    ll iter = 100;
    ld lo = minn,hi = maxx,mid,curr;
    ld ans = 1e15,left,right,midd;
	//ld high = INT_MAX , low = -1; 
	lp(i,1,iter){
    	
    	mid = (lo+hi)/2;
    	
		left = check(mid-EPS,n);
		right = check(mid+EPS,n);
		midd = check(mid,n);
		
		if(left > midd && right > midd){
			ans = midd;
			break;
		}	
		else if(left > midd && right < midd){
			lo = mid;	
			ans = min(ans,midd);
		}else{
			hi = mid;
			ans = min(ans,right);
		}	
    	
	}
	cout << fixed << setprecision(10) << ans << "\n";
	return 0;
}
    
