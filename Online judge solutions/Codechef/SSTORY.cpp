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
const ll p = 1e6 + 3, mod = 1e9 + 7;
string str1, str2;

bool check(ll len, ll &pos){
	if( !len )	return true;	//  edge case
	unordered_map<ll, ll> mp1;
	ll sz1 = str1.length(), sz2 = str2.length();
	ll hash = 0;
	ll mul = 1;
	lp(i, len){
		hash = (hash*p + str1[i])%mod;
		mul = (mul*p)%mod;
	}
	//s1.insert(hash);
	mp1[hash] = 0;
	mul = (mod - mul)%mod;
	for(ll i = len ; i < sz1 ; i++){
		//hash = (hash*p + str1[i] -(mul))%mod;
		hash = (hash*p + str1[i] + mul*str1[i - len])%mod;
		//s1.insert(hash);
		mp1[hash] = i - len + 1;
	}

	hash = 0;
	lp(i, len){
		hash = (hash*p + str2[i])%mod;
	}
	if( mp1.find(hash) != mp1.end() ){
		ll beg = mp1[hash];
		bool flag = true;
		for(ll i = 0 ; i < len ; i++){
			if(str1[beg + i] != str2[i]){
				flag = false;
				break;
			}
		}
		if( flag ){
			pos = 0;
			return false; // true ( writing binary search as 000011111 and not 11111100000 )
		}
	}
	for(ll i = len ; i < sz2 ; i++){
		hash = (hash*p + str2[i] + mul*str2[i - len])%mod;
		if( mp1.find(hash) != mp1.end() ){
			ll beg = mp1[hash];
			bool flag = true;
			for(ll j = 0 ; j < len ; j++){
				if(str1[beg + j] != str2[i - len + 1 + j]){
					flag = false;
					break;
				}
			}
			if( flag ){
				pos = i - len + 1;
				return false;	// true ( writing binary search as 000011111 and not 11111100000 )
			}	
		}
	}
	return true;	// false ( writing binary search as 000011111 and not 11111100000 )
}

int main(){
	ll t, n, m, type;
	// START HERE //		
	cin >> str1 >> str2;

	ll len1 = str1.length(), len2 = str2.length();
	ll lo = 0, hi = len2;
	
	// binary search on the length of the LCSub
	while( lo < hi ){
		ll mid = (lo + hi + 1)>>1;
		ll pos = -1;
		if( check(mid, pos) ){
			hi = mid - 1;
		}else{
			lo = mid;
		}
	}
	ll pos = -1;
	if( check(lo, pos) == false ){
		//cout << "len : " << lo << "\n";
		lp(i, lo){
			cout << str2[pos + i];
		}
		cout << "\n" << lo << "\n";
	}else{
		// return error
		cout << 0 << "\n";
	}

	return 0;
}