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
typedef pair<int,int> pii;
typedef pair<ll,ii> iii;

#define rtn return 
#define gc getchar
#define pb push_back
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,a,b) for(int i = int(a); i<=int(b) ; i++) 
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)

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
	//ios::sync_with_stdio(false);
	int t,n,m,e,w,r,a,b,p,k;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
	t = in();
	while(t--){
		n = in();
		map<string,int> mp;
		string str1,str2;
		vector< pair<int,int> > g[n+1];
		lp(i,1,n){
			cin >> str1;
			mp[str1] = i;
			cin >> p;
			lp(j,1,p){
				b = in(); w = in();
				g[i].pb(mp(b,w));
			}
		}
		
		r = in();
		
		while(r--){
			cin >> str1 >> str2;
			int id1 = mp[str1] , id2 = mp[str2];
		
			vector<int> distTo(n+1,INT_MAX);
			
			priority_queue< pii, vector< pii >, greater< pii > > q;
			
			distTo[id1] = 0;
			q.push(mp(0,id1));
			
			while(!q.empty()){
				int d = q.top().ff;
				int u = q.top().ss;
				q.pop();
				
				if( d <= distTo[u] ){
					
					lpit(it,g[u]){
					
						ll v = it->ff , cost = it->ss;
					
						if(distTo[v] > distTo[u] + cost){
							distTo[v] = distTo[u] + cost;
							q.push(mp(distTo[v],v));
						}
					
					}
				}
				
			}
			cout << distTo[id2] << "\n";
		}
		
	}
    
    
	return 0;
}
