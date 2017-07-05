/*	Persistent segment tree : For range sum query for different versions in segment tree

	O(n) time and space for building initially
	O(qlogn) for q queries , as update and range sum query are O(logn) each
	Each update creates O(logn) new nodes
	
	So, overall time complexity = O(n + qlogn),
	and overall space complexity = O(n + qlogn).

*/




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
#define midd(s,e) (s+(e-s)/2)
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
inline ll fme(ll x,ll n,ll mod){ll ans=1;x%=mod;while(n>0){if(n&1){ ans*=x;ans%=mod;} x*=x;x%=mod;n>>=1;}rtn ans%mod;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,(len/2)+2){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b,ll m) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}rtn r%m;}
inline ll sfme(ll a,ll b,ll m) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}rtn r%m;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

#define MOD 1000000007
#define N 100010
#define Q 100010
// persistent segment tree node
struct node{
	ll sum;
	node *left, *right;
	node() {}
	node( node *l, node *r, ll val){
		left = l;
		right = r;
		sum = val;
	}	
};

ll arr[N];
node *version[N];

void build( node *n, ll lo, ll hi){
	if( lo == hi ){
		n->sum = arr[lo];
		return;
	}
	
	ll mid = midd(lo,hi);
	n->left  = new node( NULL, NULL, 0);
	n->right = new node( NULL, NULL, 0); 	
	build(n->left, lo, mid);
	build(n->right, mid+1, hi);
	n->sum = n->left->sum + n->right->sum;
}

void update( node *prev, node *curr, ll lo, ll hi, ll idx, ll val){
	if( lo > hi || idx > hi || idx < lo )
		return;
	if( lo == hi ){
		curr->sum = val;	// modification in the new version
		return;
	}
	
	ll mid = midd(lo,hi);
	if( idx <= mid ){
		curr->right = prev->right;
		curr->left = new node( NULL, NULL, 0);
		update( prev->left, curr->left, lo, mid, idx, val);
	}
	else{
		curr->left = prev->left;
		curr->right = new node( NULL, NULL, 0);
		update( prev->right, curr->right, mid+1, hi, idx, val);
	}	
	
	curr->sum = curr->left->sum + curr->right->sum;
}

ll query( node *n, ll lo, ll hi, ll qlo, ll qhi){
	if( lo > hi || qlo > hi || qhi < lo )
		return 0;
	if( qlo <= lo && qhi >= hi )
		return n->sum;
	ll mid = midd(lo,hi);
	ll left = query( n->left, lo, mid, qlo, qhi);
	ll right = query( n->right, mid+1, hi, qlo, qhi);
	return left+right;
}

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,a,b,q,h,f,w,k,p;
    ///////////// START FROM HERE ////////////////////
	cin >> n >> q;
	lp(i,n)	cin >> arr[i];
	
	node *root = new node( NULL, NULL, 0);
	build( root, 0, n-1);
	version[0] = root;
	
	ll versionIndex = 0;
	while(q--){
		cout << "enter type first : \n";
		ll type;
		cin >> type;
		
		if( type ){
			ll idx, val;
			cin >> idx >> val;
			version[++versionIndex] = new node( NULL, NULL , 0);
			update( version[versionIndex-1], version[versionIndex], 0, n-1, idx, val);
		}else{
			ll qlo, qhi, qversion;
			cin >> qlo >> qhi >> qversion;
			ll res = query( version[qversion], 0, n-1, qlo, qhi);
			cout << res << "\n";
		}
		
	}
	
	
	
	return 0;
}
