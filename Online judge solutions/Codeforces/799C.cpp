/*
	AARUSH JUNEJA
	@vivace1
	TOPICS : Segment tree, binary search. 
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
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

struct node{
	ll data;
};

vector<ll> arr[2];
node seg[2][4*N];

node merge(node &a, node &b){
	node tmp;
	tmp.data = max(a.data, b.data);
	return tmp;
}

void build(ll bit,ll pos, ll lo, ll hi){
	if( lo == hi ){
		seg[bit][pos].data = arr[bit][lo];
		return;
	}
	ll mid = mid(lo,hi);
	ll l = (pos<<1)+1, r = l+1;
	build(bit,l,lo,mid);
	build(bit,r,mid+1,hi);
	seg[bit][pos] = merge(seg[bit][l],seg[bit][r]);
}

node query(ll bit, ll pos, ll lo, ll hi, ll qlo, ll qhi){
	if(qlo <= lo && qhi >= hi){
		return seg[bit][pos];
	}
	ll mid = mid(lo,hi);
	ll l = (pos<<1)+1, r = l+1;
	if(qhi <= mid)	return query(bit,l,lo,mid,qlo,qhi);
	else if(qlo > mid)	return query(bit,r,mid+1,hi,qlo,qhi);
	
	node left = query(bit,l,lo,mid,qlo,qhi), right = query(bit,r,mid+1,hi,qlo,qhi);
	
	return merge(left,right);
	
}

void update(ll bit,ll pos, ll lo, ll hi, ll idx, ll val){
	if(lo==hi){
		seg[bit][pos].data = val;
		return;
	}
	
	ll mid = mid(lo,hi);
	ll l = (pos<<1)+1, r = l+1;
	if(idx <= mid)	update(bit,l,lo,mid,idx,val);
	else update(bit,r,mid+1,hi,idx,val);
	
	seg[bit][pos] = merge(seg[bit][l],seg[bit][r]);
}
//------------------------TEMPLATE ENDS HERE--------------------------------------------------//

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,a,b,q,h,c,d,f,w,k,p;
    ///////////// START FROM HERE ////////////////////
	cin >> n >> c >> d;
	vpll cc,dd;		// both are (cost, beauty)
	lp(i,n){
		ll beauty, cost;
		char ch;
		cin >> beauty >> cost >> ch;
		if( ch == 'C' ){
			cc.pb(mp(cost, beauty));
		}else{
			dd.pb(mp(cost, beauty));
		}
	}
	
	sort(all(cc));
	sort(all(dd));
	
	vll costc(cc.size());
	vll costd(dd.size());
	
	lp(i,cc.size()){
		arr[0].pb(cc[i].second);
		costc[i] = cc[i].first;
	}
	
	lp(i,dd.size()){
		arr[1].pb(dd[i].second);
		costd[i] = dd[i].first;
	}
	
	if(!cc.empty())
		build(0,0,0,cc.size()-1);
	
	if(!dd.empty())
		build(1,0,0,dd.size()-1);		
	ll res1 = 0, res2 = 0, res3 = 0;
	
	//one coin and one diamond
	if( !cc.empty() && !dd.empty() && cc[0].ff <= c && dd[0].ff <= d ){
		ll i = 0;
		ll coin = 0,dia = 0;
		while( i < cc.size() && cc[i].ff <= c ){
			coin = max(coin,cc[i].ss);
			i++;
		}
		i = 0;
		while( i < dd.size() && dd[i].ff <= d ){
			dia = max(dia, dd[i].ss);
			i++;
		}
		res1 = coin+dia; 
	}
	
	// both coins
	if( cc.size() >= 2 && (cc[0].ff + cc[1].ff <= c)){
		lp(i,cc.size()){
			
			ll cost1 = cc[i].first;
			
			if( c-cost1 < cost1 )	continue;	
			vll::iterator it = upper_bound(costc.begin()+i+1,costc.end(),c-cost1); 
			it--;
			ll index = it-costc.begin();
			if(index == i)	
				continue;
			node q = query(0,0,0,cc.size()-1,i+1,index);	
			res2 = max( res2, q.data + cc[i].second);
		}
	}
	
	// both diamonds
	if( dd.size() >= 2 && (dd[0].ff+ dd[1].ff <= d)){
		lp(i,dd.size()){
			ll cost1 = dd[i].first;
			if( d-cost1 < cost1 )	continue;		
			vll::iterator it = upper_bound(costd.begin()+i+1,costd.end(),d-cost1);
			it--;
			ll index = it-costd.begin();
			if(index == i)	
				continue;
			node q = query(1,0,0,dd.size()-1,i+1,index);	
			res3 = max( res3, q.data+dd[i].second);
		}
	}
	
	cout << max3( res1, res2, res3) << "\n";
	
	
	
	return 0;
}
