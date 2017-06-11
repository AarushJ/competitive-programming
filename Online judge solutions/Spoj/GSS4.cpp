/*
	AARUSH JUNEJA
	@vivace
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
typedef vector<vll > matrix;
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
/*void spf_sieve(){	for(ll i=2 ; i<MAX ; i++){ if(i&1) spf[i] = i; else spf[i] = 2;}	
	for(ll i=3 ; i<MAX ; i+=2){	if(spf[i]==i){  for(ll j=i*i ; j<=MAX ; j+=i){ if(spf[j]==j) spf[j] = i; } } }
}*/
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

struct node{
	ll val;
	bool flag,lflag,rflag;
};

node seg[400005];
ll v[100005];

node merge(node &a, node &b){
	node tmp;
	if( a.flag && b.flag )	tmp.flag = true;
	else tmp.flag = false;
	tmp.val = a.val + b.val;
	return tmp;
}

void build(ll pos, ll lo, ll hi){
	//cout << "entered b"
	if( lo > hi )	return; 
	if( lo == hi ){
		seg[pos].val = v[lo];
		if( v[lo] == 1 )	seg[pos].flag = true;
		else seg[pos].flag = false;
		return;
	}
	ll mid = (lo+hi)>>1; 
	ll l = pos+pos+1, r = l+1;
	build(l, lo, mid);
	build(r, mid+1, hi);
	seg[pos] = merge(seg[l], seg[r]);
}

node query(ll pos, ll lo, ll hi, ll qlo, ll qhi){
	if( lo > hi || qlo > hi || qhi < lo ){
		node res;
		res.val = 0;
		return res;
	}	
	if( qlo <= lo && qhi >= hi ){
		return seg[pos];
	}	
	
	ll mid = (lo+hi)>>1;
	ll l = pos+pos+1, r = l+1;
	node left = query(l, lo, mid, qlo, qhi);
	node right = query(r, mid+1, hi, qlo, qhi);
	return merge(left,right);
}

void update(ll pos, ll lo, ll hi, ll qlo, ll qhi){
	//cout << "entered update with pos : " << pos << " lo : " << lo << " hi : " << hi << " index : " << index << "\n";
	if(lo > hi || lo > qhi || hi < qlo){
		//cout << "entered first if and hence returning without updating as it is out of range\n";
		return;
	}	
	if( seg[pos].flag ){
		//cout << "seg[" << pos << "].flag is true, so returning as 1 ban chuka hai\n"
		return;
	}	
	if( lo == hi ){
		//cout << "lo == hi, so putting sqrt value and other values and returning\n";
		seg[pos].val = sqrt(seg[pos].val);
		if( seg[pos].val == 1 )	seg[pos].flag = true;
		v[lo] = seg[pos].val;
		return;
	}
	ll mid = (lo+hi)>>1;
	ll l = pos+pos+1, r = l+1;
	//cout << "mid : " << mid << " l : " << l << " r : " << r << "\n";
	update(l, lo, mid, qlo, qhi);
	//cout << "came back to update with pos : " << pos << " lo : " << lo << " hi : " << hi << " index : " << index << "\n";
	update(r, mid+1, hi, qlo, qhi);
	//cout << "came back to update with pos : " << pos << " lo : " << lo << " hi : " << hi << " index : " << index << "\n";
	seg[pos] = merge(seg[l],seg[r]);
	
}	

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,a,b,q,h,f,w,x,y,k,p;
    ///////////// START FROM HERE ////////////////////
    ll testCase = 0;
	while(scanf("%lld",&n) != EOF){
		testCase++;
		lp(i,n)	scanf("%lld", &v[i]);	
		build(0,0,n-1);
		//cout << "TREE : \n";
		//lp(i,4*n)	cout << "(" << seg[i].val << "," << seg[i].flag <<   ") ";cout << "\n\n\n\n";
		scanf("%lld",&q);
		ll type,l,r; 
		bool flag = false;
		while(q--){
			scanf("%lld %lld %lld",&type,&l,&r);
			l--; r--; 
			//cout << "type : " << type << " l : " << l << " r : " << r << "\n";
			if( l > r )	swap (l,r);
			//cout << "swapped l and r : " << l << " to " << r << "\n";
			if( type ){ 
				if( !flag ){
					flag = true;
					printf("Case #%d:\n",testCase);
				}
				cout << query(0,0,n-1,l,r).val << "\n";
			}else{
				//cout << "update query : \n";
				//for(ll i = l ; i<= r ; i++){
					//cout << "i : " << i << "\n";
					//if(v[i] > 1){
						//cout << "v[" << i << "] > 1, so doing update\n";
					update(0,0,n-1,l,r);	
					//}//else{
						//cout << "v[" << i << "] <= 1, so not doing update\n"; 
					//} 
				//}
			}
			//lp(i,4*n)	cout << "(" << seg[i].val << "," << seg[i].flag <<   ") ";cout << "\n";
		}
	}	
			
	return 0;
}

