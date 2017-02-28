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
#define ff first
#define ss second
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

void init(int par[],int sz[],int n){
	lp(i,0,n){
		sz[i] = 1;
		par[i] = i;
	}
}

int find(int par[],int i){
	while(par[i]!=i)	i = par[par[i]];
	return i;
}

void merge(int par[],int sz[],int u,int v){
	int a = find(par,u) , b = find(par,v);
	if(sz[a] < sz[b]){
		par[a] = b;
		sz[b] += sz[a];
	}else{
		par[b] = a;
		sz[a] += sz[b];
	}
}

bool areConn(int par[],int a,int b){
	return (find(par,a)==find(par,b));
}

int main(){
	ios::sync_with_stdio(false);
	
	int t,v,e,p,a,b,w;
	cin >> t;
	while(t--){
		cin >> p;
		cin >> v >> e;
		int par[v] , sz[v];
		init(par,sz,v);
		vector<pair<int,pair<int,int> > > edges(e);
		lp(i,0,e){
			cin >> a >> b >> w;
			edges[i] = mp(w,mp(a-1,b-1));
		}
		sort(all(edges));
		
		int count = 0,treeVal = 0;
		lp(i,0,e){
			if(!areConn(par,edges[i].ss.ff,edges[i].ss.ss)){
				treeVal += edges[i].ff;
				merge(par,sz,edges[i].ss.ff,edges[i].ss.ss);
				count++;
				if(count==v-1)	break;
			}
		}
		cout << treeVal*p << "\n";
	}
	
	return 0;
}
