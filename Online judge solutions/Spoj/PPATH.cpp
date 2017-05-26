/*
	AARUSH JUNEJA
	@vivace
	TOPICS : sieve of eratosthenes, breadth first search, shortest path in an unweighted graph
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
bool isPrime[MAX];
//int spf[MAX];
//////////////////////////////////////////// FUNCTIONS THAT NEED COMMENTED OUT CONTAINERS ////////////////////////////////////


void prime_sieve(){ for(ll i=2 ; i*i<=MAX ; i++){	if(!isPrime[i]){ for(ll j=i*i ; j<=MAX ; j+=i)	isPrime[j] = 1;} } 	}
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
vector<int> g[100010];

bool differByOneDigit(int a, int b){
	int cnt = 0;
	lp(i,4){
		int one = a%10, two = b%10;
		if( one != two )
			cnt++;
		a/=10;
		b/=10;
	}
	if( cnt == 1 )	return true;
	return false;
}

int distTo[100010];
bool mark[100000];
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int t,n,m,e,a,b,q,h,f,w,x,y,k,p;
    ///////////// START FROM HERE ////////////////////
	
	prime_sieve();
	vector<int> primes;
	lp(i,100010)
		distTo[i] = INT_MAX;
	for(int i = 1001 ; i<= 9999 ; i++){
		if( !isPrime[i] )	// isPrime[i] == true actually means not prime (implementation based)
			primes.pb(i);
	}
	
	for(int i = 0 ; i<primes.size() ; i++){
		for(int j = i+1 ; j<primes.size() ; j++){
			if( differByOneDigit(primes[i],primes[j]) ){
				g[primes[i]].pb(primes[j]);
				g[primes[j]].pb(primes[i]);
			}
		}
	}
	cin >> t;
	while(t--){
		cin >> a >> b;
		for(ll i = 1000 ; i <= 9999 ; i++){
			distTo[i] = INT_MAX;
			mark[i] = false;
		}
		queue<int> q;
		q.push(a);
		distTo[a] = 0;
		mark[a] = true;
		while( !q.empty() ){
			int curr = q.front();
			q.pop();
			lpit(it,g[curr]){
				if( !mark[*it] ){
					q.push(*it);
					mark[*it] = true;
					distTo[*it] = distTo[curr] + 1;
				}
			}
		}
		
		if( distTo[b] != INT_MAX ) cout << distTo[b] << "\n";
		else cout << "Impossible\n";
	}
	
	return 0;
}
