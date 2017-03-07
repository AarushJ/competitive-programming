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
#define N 200100

ll par[N],color[N],col[N];
bool mark[N];

list<ll> g[N];

void dfs(ll start){
    mark[start] = true;
    lpit(it,g[start]){
        if(!mark[*it]){
            par[*it] = start;
            dfs(*it);
        }
    }
}

void bfs(ll start){
    queue<ll> q;
    q.push(start);
    col[start] = 2;
    color[start] = 1;
    
    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        lpit(it,g[curr]){
            if(!mark[*it]){
                mark[*it] = true;
                q.push(*it);
                color[*it] = col[par[*it]];
                
                col[par[*it]]++;
                
                // to check parent and child don't get same color
                if(col[par[*it]]==color[par[*it]] || col[par[*it]]==color[par[par[*it]]]){
                	col[par[*it]]++;
				}
				if(col[par[*it]]==color[par[*it]] || col[par[*it]]==color[par[par[*it]]]){
                	col[par[*it]]++;
				}
                
                // to check that the first color the child will give to grandChild is not same as child and parent of child
                if( color[*it] != 1 && color[par[*it]] != 1 ){
                    col[*it] = 1;
                }else if( max(color[par[*it]],color[*it])-min(color[*it],color[par[*it]]) == 1 ){
                    col[*it] = max(color[*it],color[par[*it]]) + 1;
                }else{
                    col[*it] = min(color[*it],color[par[*it]]) + 1;
                }
                
                
            }
        }
    }

}

int main(){
    //ios::sync_with_stdio(false);
	ll t,n,m,e,a,b,k;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
    cin >> n;
    
    lp(i,1,n-1){
    	cin >> a >> b;
    	g[a].pb(b);
    	g[b].pb(a);
	}
    
    memset(mark,false,sizeof(mark));
    
    dfs(1);
    
    par[1] = 0;
    col[0] = 1;
    color[0] = 0;
    
    memset(mark,false,sizeof(mark));
	
    bfs(1);
    
    ll maxx = -1;	
    
    
    
    lp(i,1,n){
    	maxx = max(maxx,color[i]);
	}
	
	cout << maxx << "\n";
    lp(i,1,n)	cout << color[i] << " ";
	cout << "\n";
    return 0;
}
