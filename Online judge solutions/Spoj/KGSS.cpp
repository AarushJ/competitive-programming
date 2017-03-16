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
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}


//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

#define MOD 1000000007
#define N 100010

struct node{
	ll val;
	ll index;
};

ll arr[N];

node tree[4*N];

node merge(node a,node b){
	node res;
	if(a.val > b.val){
		res = a;
	}else{
		res = b;
	}
	return res;
}

void build(ll pos, ll lo, ll hi){
	if(lo==hi){
		tree[pos].val = arr[lo];
		tree[pos].index = lo;
		return;
	}
	
	ll mid = mid(lo,hi);
	ll left = (pos<<1)+1, right = left+1;
	build(left, lo, mid);
	build(right, mid+1, hi);
	
	tree[pos] = merge(tree[left],tree[right]);

}

node query(ll pos, ll lo, ll hi, ll qlo, ll qhi){

	if(qlo<=lo && qhi>=hi)	return tree[pos];
	ll mid = mid(lo,hi);
	ll left = (pos<<1)+1, right = left+1;
	
	if(qhi <= mid){
		return query(left,lo,mid,qlo,qhi);
	}else if(qlo > mid){
		return query(right,mid+1,hi,qlo,qhi);
	}
	
	node lNode = query(left,lo,mid,qlo,qhi);
	node rNode = query(right,mid+1,hi,qlo,qhi);
	
	return merge(lNode,rNode); 
	
}

void upd(ll pos, ll lo, ll hi,ll idx, ll newVal){
	if(lo==hi){
		arr[idx] = newVal;
		tree[pos].val = newVal;
		return;	
	}
	ll mid = mid(lo,hi);
	ll left = (pos<<1)+1, right = left+1;
	
	if(idx<=mid){
		upd(left,lo,mid,idx,newVal);
	}else{
		upd(right,mid+1,hi,idx,newVal);
	}
	tree[pos] = merge(tree[left],tree[right]);
}


int main(){
	ios::sync_with_stdio(false);
	ll t,n,m,e,a,b,q,w,k;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
	cin >> n;
	lp(i,0,n-1)	cin >> arr[i];
    
    build(0,0,n-1);
    
    cin >> q;
    while(q--){
    	char type;
		cin >> type;
		if(type == 'U'){
			ll idx,newVal;
			cin >> idx >> newVal;
			upd(0,0,n-1,idx-1,newVal);
		}else{
			ll x,y;
			cin >> x >> y;
			node max1 = query(0,0,n-1,x-1,y-1);
			ll index = max1.index;
			
			upd(0,0,n-1,index,-1);
			
			node max2 = query(0,0,n-1,x-1,y-1);	
			
			cout << max1.val + max2.val << "\n";
			
			upd(0,0,n-1,index,max1.val);
			
		}
	}
    
    
	return 0;
}
