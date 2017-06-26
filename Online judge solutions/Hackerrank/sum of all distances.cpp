#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 100010

typedef double lf;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<pair<ll,ll > >vpll;
typedef vector<vll > vvll;

#define sd(a) scanf("%d",&a)
#define sstr(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define debug(a) printf("check%d\n",a)
#define clr(a) memset(a,0,sizeof(a))
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

vpll g[100005];
vll subsize(100005), sum(100005), ans(100005);//sum[i]=>sum of dist from current node(i) to all other nodes in the subtree rooted at current node(i)
vector<bool> mark(100005);
ll n;	// total nodes

// calculate subsize[] and sum[] for each node
void dfs1(ll v){
	mark[v] = true;
	lpit(it, g[v]){
		if( !mark[ it->ff ] ){
			dfs1( it->ff );
			subsize[ v ] += subsize[ it->ff ];
			sum[v] += sum[ it->ff ] + (subsize[ it->ff ] * it->ss);
		}
	}
	subsize[v]++;
}

// calculate answer for each node in 1 go
void dfs2(ll v){
	mark[v] = true;
	if( v == 1 ){
		ans[v] = sum[v];
	}
	lpit(it, g[v]){
		if( !mark[ it->ff ]){
			ans[ it->ff ] = sum[ it->ff ] + (ans[v] - (it->ss*(subsize[ it->ff ])) - sum[ it->ff ]);
            ans[ it->ff ] += it->ss * (n - subsize[ it->ff ]);
			dfs2( it->ff );
		}
	}
}

int main(){
	ll t, m, v, p, q, k, a, b, c, d, e , f , h, type, w, x, y, z;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while(t--){
		cin >> n;
		lp(i, n+1) mark[i] = false, subsize[i] = ans[i] = 0, sum[i] = 0, g[i].clear();
		lp(i, n-1){
			cin >> a >> b >> w;
			g[a].pb(mp(b, w)); 
			g[b].pb(mp(a, w));
		}
		dfs1(1);
		lp(i, n+1)	mark[i] = false;
		dfs2(1);
		lp(i, n)	cout << ans[i+1] << "\n";
	}
	
	return 0;
}
