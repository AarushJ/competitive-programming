/*
	AARUSH JUNEJA
	@vivace
	TOPICS : matrix exponentiation
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
matrix mul(matrix a,matrix b,ll rowSize,ll mod){matrix c(rowSize, vll (rowSize));lp(i,rowSize){lp(j,rowSize){
	ll sum = 0;lp(k,rowSize){sum = (sum + (a[i][k]*b[k][j]))%mod;;}	c[i][j] = sum;}} return c;}
matrix exp(matrix a,ll p,ll rowSize,ll mod){if(p==1)return a;if(p&1)return mul(a,exp(a,p-1,rowSize,mod),rowSize,mod);
	matrix 	x = exp(a,p/2,rowSize,mod);	return mul(x,x,rowSize,mod);}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//
vector<ll> F1(20), c(20);

ll solve(ll k,ll n,ll mod){
	matrix T(k, vector<ll>(k) );
	T[0][0] = 1;
	// matrix built
	lp(i,k){
		lp(j,k){
			if( i+1 == j )
				T[i][j] = 1;
			else if( i == k-1 && j )
				T[i][j] = c[k-j-1];
		}
	}
	
	if( n < k )	return F1[n]%mod;
	T = exp(T,n,k,mod);
	ll res = 0;
	lp(i,k)
		res = (res + (T[0][i]*F1[i])%mod)%mod; 
	return res%mod;
}


int main(){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,a,b,q,h,f,w,x,y,k,p;
    ///////////// START FROM HERE ////////////////////
    cin >> t;
    while(t--){
    	k = 2;
    	k++; // because F1 is of (k+1)*1 dimensions and T (transition matrix) is of (k+1)*(k+1) dimensions
		F1[0] = 0;	// sum till F[0]
    	F1[1] = 0;
    	F1[2] = 1;
    	c[0] = 1;
    	c[1] = 1;
		cin >> n >> m;
		n++; m++;	// Scale change (my matrix method is 1 indexed)
    	ll mod = 1000000007;
    	ll a = solve(k,m,mod), b = solve(k,n-1,mod);
		ans = (a-b+mod)%mod;
		cout <<  ans << "\n";
	}
		
			
	return 0;
}
