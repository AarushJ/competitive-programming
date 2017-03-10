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
typedef pair<ll,ll> pii;
typedef vector<pii> vpll;
typedef map<ll,ll> mll;
typedef vector<vll > vvll;
typedef list<ll> lll;
typedef vector<lll > vlll;
typedef pair<ll,pii> iii;

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
#define MAX 200100

inline int in()
{
    int NR=0;
    register char c=gc();
    while( c < 48 || c > 57 ){c=gc();}
    while(c>47 && c< 58)
    {
		NR = (NR << 3) + (NR << 1) + (c - 48);
		c=gc();
    }
    return NR;
}

int main(){
	ios::sync_with_stdio(false);

	ll t,n,m,e,a,b,w,k,beg,end;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
    cin >> t;
    while(t--){
    	cin >> n >> m >> beg >> end; 
    	vector<pair<ll,ll> > g[n+1];
		
		while(m--){
			cin >> 	a >> b >> w;
			g[a].pb(mp(b,w));
			g[b].pb(mp(a,w));
		}
		
		vector<ll> distTo(n+1,INT_MAX);
		
		
		priority_queue< pii, vector< pii >, greater<pii> > q;
		distTo[beg] = 0;
		q.push(mp(0,beg));		// (dist,from)
		
		while(!q.empty()){
			int dist = q.top().ff;
			int prev = q.top().ss;
			
			q.pop();
			
			if(dist <= distTo[prev] ){
				
				lpit(it,g[prev]){
					
					ll next = it->ff , cost = it->ss;
					
					if(distTo[next] > distTo[prev] + cost ){
						distTo[next] = distTo[prev] + cost;
						q.push(mp(distTo[next],next));
					}
					
				}
							
			}
	
		}
		
		if(distTo[end]==INT_MAX){
			cout << "NONE\n";
		}else{
			cout << distTo[end];
		} 
		
    }
    
    
	return 0;
}
