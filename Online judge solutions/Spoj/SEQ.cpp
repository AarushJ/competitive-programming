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

#define MOD 1000000000
#define N 100010

inline int in(){
    int NR=0;
    register char c=gc();
    while( c < 48 || c > 57 ){c=gc();}
    while(c>47 && c< 58){
		NR = (NR << 3) + (NR << 1) + (c - 48);
		c=gc();
    }
    return NR;
}

matrix mul(matrix a, matrix b, ll d){
	matrix c(d, vll (d));
	lp(i,0,d-1){
		lp(j,0,d-1){
			ll sum = 0;
			lp(k,0,d-1){
				sum = (sum + (a[i][k]*b[k][j]))%MOD;;	
			}
			c[i][j] = sum;
		}
	}
	return c;
}

matrix exp(matrix a,ll p,ll d){
	if(p==1)	return a;
	if(p&1)	return mul(a,exp(a,p-1,d),d);
	matrix 	x = exp(a,p/2,d);
	return mul(x,x,d);
}

ll fib(vll &f1,vll &c,ll k,ll n){
	
	matrix t(k,vll (k));
	
	lp(i,0,k-1){
		lp(j,0,k-1){
			if(i==k-1){
				t[i][j] = c[k-1-j];
			}else if(j==i+1){
				t[i][j] = 1;
			}else{
				t[i][j] = 0;
			}
		}
	}
	
	/*lp(i,0,k-1){
		lp(j,0,k-1){
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}*/
	
	
	if(n<k)	return f1[n-1]%MOD;
	
	t = exp(t,n-1,k);
	
	ll res = 0;
	
	lp(i,0,k-1)		res = (res + (t[0][i]*f1[i]))%MOD; 
	
	return res%MOD;
	
}

int main(){
	ios::sync_with_stdio(false);
	ll t,n,m,e,a,b,q,w,k;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
 	cin >> t;
	while(t--){
    	cin >> k;
    	vll f1(k),c(k);
    	
		lp(i,0,k-1)	cin >> f1[i];
    	lp(i,0,k-1)	cin >> c[i];
		cin >> n;    	
    	cout << fib(f1,c,k,n) << "\n";
    	
	}
	
	return 0;
}
