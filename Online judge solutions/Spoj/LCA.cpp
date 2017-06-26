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

#define NMAX 100005
#define LOGNMAX 20
vector<int> g[NMAX];
int father[NMAX], par[NMAX][LOGNMAX+1], depth[NMAX];
vector<bool> mark(NMAX);	// vector<bool> works faster than array of bool

// for assigning parents
void dfs(int v){
	mark[v] = true;
	lpit(it, g[v]){
		if( !mark[*it]){
			father[*it] = v;
			depth[*it] = depth[v] + 1;
			dfs(*it);
		}
	}
}

void build_LCA_sparse(int n){

	for(int i = 0 ; i<n ; i++){
		for(int j = 0; j<=LOGNMAX ; j++){
			par[i][j] = -1;
		}
	}

	for(int i = 0 ; i<n ; i++)	par[i][0] = father[i];	
	for(int j = 1; j<=LOGNMAX ; j++){
		for(int i = 0 ; i<n ; i++){
			int mid = par[i][j-1];
			if( mid != -1 )
				par[i][j] = par[mid][j-1];
		}
	}
}

int jump(int x, int d){
	for(int i = LOGNMAX-1 ; i>=0 ; i--){
		if( (1<<i) <= d ){
			x = par[x][i];
			d -= (1<<i);
		}
	}
	return x;
}

// query LCA in O( logn + logNMAX ) in the worst case
int LCA(int a, int b){
	if( depth[a] > depth[b] )	a = jump(a, depth[a]-depth[b]);
	if( depth[b] > depth[a] )	b = jump(b, depth[b]-depth[a]);

	// b is ancestor of a or a is ancestor of b
	if( a == b )	return a;
	for(int i = LOGNMAX-1 ; i>=0 ; i--){
		if( par[a][i] != par[b][i] ){
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

int main(){
	ll t, n, m, v, p, q, k, a, b, c, d, e , f, type, x, y, z;
	cin >> t;
	for(ll tt = 1 ; tt<=t ; tt++){
		cin >> n;
		lp(i, n){
			cin >> m;
			lp(j, m){
				cin >> b;
				b--;
				g[i].pb(b);
				g[b].pb(i);
			}
		}
		depth[0] = 0;
		father[0] = -1;
		dfs(0);
		build_LCA_sparse(n);

		cin >> q;
		cout << "Case " << tt << ":\n";
		while(q--){
			cin >> a >> b;
			a--; b--;
			cout << LCA(a, b)+1 << "\n";
		}

		lp(i, n)	father[i] = 0, depth[i] = 0, mark[i] = false, g[i].clear();	

	}
		


	return 0;
}
