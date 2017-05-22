/* Ab ki baar 1900 paar */
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

vll l,r,lefts,rights;
vll v;

bool overFlow( ll a, ll b){
	ll x = a*b;
	if( a != 0 && (x/a != b))
		return true;
	return false;
}

ll brute( vector<ll> &v, ll k){
	ll n = v.size(), ans = 0;
	for( ll mask = 0 ; mask < ( 1 << n ) ; mask++){
    	ll pdt = 1;
    	bool flag = false;
    	for(ll i = 0 ; i<n ; i++){
    		if( mask & (1 << i) ){
    			flag = true;
    			ll initialPdt = pdt;
				pdt *= v[i];
				if( pdt > k || overFlow(initialPdt, v[i])){
					flag = false;
					break;
				}
			}
		}
    	
    	if( flag ){
    		ans++;	
		}	
	}
	return ans;
}

ll binarySearch( vll &r, ll lval, ll k){
	ll lo = 0, hi = r.size()-1;

	while( lo < hi){
		ll mid = (lo+hi+1)/2;
		if( r[mid]*lval <= k && !overFlow(r[mid],lval) ){
			lo = mid;			
		}else{
			hi = mid-1;
		}		
	}
	return lo;
}

ll chakkDeFatte( ll k){
	ll n = l.size();
	
	for(ll mask = 0 ; mask < (1<<n) ; mask++){
		ll pdt = 1;
    	bool flag = false;
    	for(ll i = 0 ; i<n ; i++){
    		if( mask & (1 << i) ){
    			flag = true;
    			ll initialPdt = pdt;
				pdt *= l[i];
    			if(pdt > k || overFlow( initialPdt, l[i]) ){
					flag = false;
					break;
				}
			}
    	}
    	if( flag ) lefts.pb(pdt);
	}
	
	n = r.size();

	for(ll mask = 0 ; mask < (1<<n) ; mask++){
		ll pdt = 1;
    	bool flag = false;
    	for(ll i = 0 ; i<n ; i++){
    		if( mask & (1 << i) ){
    			flag = true;
    			ll initialPdt = pdt;
    			pdt *= r[i];
    			if(pdt > k || overFlow( initialPdt, r[i]) ){
					flag = false;
					break;
				}
			}
    	}
		if( flag ) rights.pb(pdt);
	}
	
	sort(all(lefts));
	sort(all(rights));
	
	ll ans = brute( l, k );	
	//cout << "ans after brute on left : " << ans << "\n";
	ans += brute( r, k) ;
	//cout << "ans after brute on right : " << ans << "\n";
	vector<ll>::iterator ub;
	
	ll lsz,rsz;
	lsz = lefts.size(), rsz = rights.size();
	
	//cout << "entering binary search loop : \n";
	lp(i,lsz){
		if( rights[rsz-1]*lefts[i] <= k && !overFlow( rights[rsz-1], lefts[i]) ){
			ans += rsz;
		}else if( overFlow( rights[0], lefts[i]) || rights[0]*lefts[i] > k ){
			continue;
		}else{
			//ans += upper_bound( all(rights), k/lefts[i])-rights.begin();
			ans += (binarySearch( rights, lefts[i], k)+1);		
		}
	}
	
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,a,b,q,h,f,w,k,p;
    ///////////// START FROM HERE ////////////////////
    
    cin >> n >> k;
	for(ll i = 0 ; i<n/2 ; i++){
		cin >> a;
		if( a <= k )
			l.pb(a);
	}
	for(ll i =n/2 ; i<n ; i++ ){
		cin >> a;
		if( a <= k )
			r.pb(a);
	}
	ll res = chakkDeFatte(k);	
	cout << res << "\n";	
	return 0;
}
