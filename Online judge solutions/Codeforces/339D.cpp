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
ll makeNum(string &str){ll a = 0;	lpit(it, str){ int num = *it - '0';	a = a*10 + num;} return a;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

ll arr[1<<18], seg[1<<20];

ll merge(int l, int r, int level){
	if( level & 1 ){
		return seg[l] | seg[r];
	}else{
		return seg[l] ^ seg[r];
	}
}

int build(int pos, int lo, int hi){
	if( lo > hi )	return -1;
	if( lo == hi ){
		seg[pos] = arr[lo];
		return 1;
	}
	int mid = (lo+hi)>>1, l = pos + pos + 1, r = l + 1;
	int level1 = build(l, lo, mid);
	int level2 = build(r, mid+1, hi);
	int level;
	if( level1 != -1 )	level = level1;
	else level = level2;
	seg[pos] = merge(l, r, level);
 	return level + 1;
}

int update(int pos, int lo, int hi, int index, int val){
	if( lo > hi || index < lo || index > hi ){
		return -1;
	}

	if( lo == hi ){
		arr[lo] = seg[pos] = val;
		return 1;
	}
	int mid = (lo+hi)>>1, l = pos + pos + 1, r = l + 1;
	int level1 = update(l, lo, mid, index, val);
	int level2 = update(r, mid+1, hi, index, val);
	int level;
	if( level1 != -1 )	level = level1;
	else level = level2;
	seg[pos] = merge(l, r, level);
	return level + 1;
}

int main(){
	ll t, n, m, v, p, q, k, a, b, c, d, e , f, type, x, y, z;
	// START HERE //		
	cin >> n >> m;
	lp(i, 1<<n ){
		cin >> arr[i];
	}
	build(0, 0, (1<<n)-1);
	while( m-- ){
		ll index, val;
		cin >> index >> val;
		update(0, 0, (1<<n)-1, index-1, val);
		cout << seg[0] << "\n";
	}

	return 0;
}