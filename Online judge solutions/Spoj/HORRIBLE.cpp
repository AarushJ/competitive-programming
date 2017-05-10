/*  Ab ki baar 1900 paar  */
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

vector<ll> v(N);
vector<ll> tree(4*N), lazy(4*N);
 
ll merge( ll left, ll right){
	ll tmp;
	tmp = left + right ;
	return tmp;
}

void ulazy( ll pos, ll lo, ll hi, ll qlo, ll qhi, ll val){
	
	ll l = (pos<<1)+1, r = l+1;
	
	if( lazy[pos] ){	// if there are pending updates to current node
		tree[pos] += (hi-lo+1)*lazy[pos];	
			
		if( lo != hi ){		
			lazy[l] += lazy[pos];
			lazy[r] += lazy[pos];
		}	
		
		lazy[pos] = 0;
	}	
	
	if( lo > hi || lo > qhi || hi < qlo )
		return;
	
	if( qlo <= lo && hi <= qhi ){	// queried segment totally overlaps the current range of function
		tree[pos] += (hi-lo+1)*val;
		if( lo != hi ){
			lazy[l] += val;
			lazy[r] += val;
		} 		
		return;
	}	
	
	ll mid = mid(lo,hi);
	
	ulazy( l, lo, mid, qlo, qhi, val);
	ulazy( r, mid+1, hi, qlo, qhi, val);
	
	tree[pos] = merge( tree[l], tree[r] );
	
}

ll qlazy( ll pos, ll lo, ll hi, ll qlo, ll qhi){
	
	ll l = (pos<<1)+1, r = l+1;
	
	if( lo > qhi || lo > hi || hi < qlo	)
		return 0;
	
	if( lazy[pos] ){	// if there are pending updates to current node
		tree[pos] += (hi-lo+1)*lazy[pos];	
			
		if( lo != hi ){		
			lazy[l] += lazy[pos];
			lazy[r] += lazy[pos];
		}	
		
		lazy[pos] = 0;
	}
	
	if( qlo <= lo && qhi >= hi )	// the segment of current node is completely inside queried range
		return tree[pos];
		
	ll mid = mid( lo , hi );
	
	if( qlo > mid)
		return qlazy( r, mid+1, hi, qlo, qhi);
	else if( qhi <= mid)
		return qlazy( l, lo, mid, qlo, qhi);
		
	ll left = qlazy( l, lo, mid, qlo, qhi);
	ll right = qlazy( r, mid+1, hi, qlo, qhi);	
		
	return merge( left, right);
}

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,a,b,c,q,h,w,k,p;
    ///////////// START FROM HERE ////////////////////
	cin >> t;
	while(t--){
		cin >> n >> q;
		
		lp(i, 4*n + 1){
			lazy[i] = 0;
			tree[i] = 0;	
		}
		
		while(q--){
			ll type;
			
			cin >> type;
			
			if( !type ){
				ll l, r, val;
				cin >> l >> r >> val;
				l--; r--;
				
				ulazy( 0, 0, n-1, l, r, val);				
			
			}else{
				ll l,r;
				cin >> l >> r;
				l--; r--;
				
				ll res = qlazy( 0, 0, n-1, l, r);
				cout << res << "\n";
				
			}	
		
			
		}
		
		
	}
	
	
	
	return 0;
}
