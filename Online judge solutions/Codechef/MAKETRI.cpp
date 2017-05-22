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
#define f first
#define s second
#define mp(x,y) make_pair(x,y)
#define sz size()
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,a,b) for(int i = int(a); i<int(b) ; i++) 
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
inline bool isPalin(string &s){	int len = s.sz-1;lp(i,0,(len/2)+1){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)%gcd(a,b); }
inline ll fmm(ll a,ll b,ll m) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}rtn r%m;}
inline ll sfme(ll a,ll b,ll m) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}rtn r%m;}

// ncr mod p
// inverse modulo
// fermat
// lucas/wilson
// smallest prime factor sieve

int main(){
	ios::sync_with_stdio(false);
	ll t,n,k,m,maxx = 0,minn = 0,beg = 0,end = 0,lo = 0,hi = 0,l = 0, r = 0,count = 0,sum = 0,pos = 0;

	cin >> n >> l >> r;
	vll v(n);
	vpll inter(n),inter2(n);
	lp(i,0,n){
		cin >> v[i];
	}
	sort(all(v));	

	for(int i=1 ; i<n ; i++){    // bringing the intervals in range
		   inter[i].f = v[i]-v[i-1]+1;		
		   inter[i].s = v[i]+v[i-1]-1;
		   if((inter[i].f < l && inter[i].s < l) || (inter[i].f > r && inter[i].s>r)){
		   	 inter[i].f = -1;
		   	 inter[i].s = -1;
		   }else if(inter[i].f < l && inter[i].s<=r){
		   	inter[i].f = l;
		   }else if(inter[i].f>=l && inter[i].s > r){
		   	inter[i].s = r;
		   }
	}
	sort(all(inter));
	
	int index = 0;
	int i=0;
	for( i=1 ; i<n ; i++){
		if(inter[i].f!=-1){
			break;
		}	
	}
	
	index = i;
	
	stack<ii> st;
	st.push(inter[index]);
	for(i=index+1 ; i<n ; i++){
		ii tt = st.top();
		if(tt.s < inter[i].f)	st.push(inter[i]);
		else if(tt.s < inter[i].s){
			tt.s = inter[i].s;
			st.pop();
			st.push(tt);
		}
	}
	
	ll ans = 0;
	while(!st.empty()){
		if(!(st.top().s==0 && st.top().f==0)){
			ans += st.top().s - st.top().f+1;
		}
		st.pop();
	}
	cout << ans ;
	
	
	
	return 0;
}



