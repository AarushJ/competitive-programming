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

#define MOD 1000000007
#define N 1000099

vector<pair<ll,pair<ll,ll> > > g(N);

ll par[N],sz[N];
void init(ll n){
	lp(i,1,n){
		par[i] = i;
		sz[i] = 1;
	}
}

ll find(ll i){
 	while( i != par[i] ){
		par[i] = par[par[i]];	// path compression 
		i = par[i];
	} 	
	return i;
}

void merge(ll u,ll v){
	ll a = find(u);
	ll b = find(v);
	if(a==b)	return; // union by size
	if( sz[a] < sz[b] ) { par[a] = b; sz[b]+=sz[a];	}
	else				{ par[b] = a; sz[a]+=sz[b];	}
}

bool areConn(ll u,ll v){
	return (find(u)==find(v));
}

int main(){
	//ios::sync_with_stdio(false);
	ll t,n,m,e,a,b,k,w;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
 	cin >> t;
	while(t--){
		cin >> n >> m;
		lp(i,1,m){
			cin >>	a >> b >> w;  
			g[i] = mp(-w,mp(a,b)); // pushing back negative weight into the vector so that kruskal gives maximal spanning tree 
		}
		sort(g.begin()+1,g.begin()+m+1);
		init(n);
		ll cnt = 0, treeVal = 0;
		lp(i,1,m){
			ll u = g[i].ss.ff , v = g[i].ss.ss;
			if(!areConn(u,v)){
				cnt++;
				treeVal += g[i].ff;
				merge(u,v);
				if(cnt==n-1)	break;
			}		
		}
		cout << -treeVal << "\n";	// negative of the weight found by kruskall would be the weight of the maximal spanning tree
	}	   
    
    
	return 0;
}
