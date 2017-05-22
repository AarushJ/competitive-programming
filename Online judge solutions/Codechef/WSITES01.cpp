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
#define SIZE 26

set<string> ans;
stack<char> st;
string tmp;

// trie node
struct node{
	char data;
	node *parent;
	node *child[SIZE];
	ll unblockedWords;
	ll blockedWords;
	ll words;
	ll prefixes;
	bool partOfBlocked;
	bool partOfUnblocked;
};

ll search( node *a, string &s);

node* newNode(){
	node *a = new node;
	a->data = '0';
	a->words = 0;
	a->blockedWords = 0;
	a->unblockedWords = 0;
	a->prefixes = 0;
	a->partOfBlocked = false;
	a->partOfUnblocked = false;
	lp(i,SIZE)	a->child[i] = NULL;
	return a;
}

void sumWords( node *a){
	a->words = a->blockedWords + a->unblockedWords;
}

void insert( node *a, string &str, bool blocked, bool &check){
	node* ptr = a;
	ll sz = str.size();
	lp(i,sz){
		ll idx = str[i]-'a';
		
		// check if newNode is required
		if( ptr->child[idx] == NULL ){
			ptr->child[idx] = newNode();
			ptr->child[idx]->parent = ptr;
			if( !blocked && ptr->blockedWords ){
				check = false;	// if string is unblocked and a blocked string is its prefix
				return;
			}
		}
					
		ptr = ptr->child[idx];
		ptr->data = str[i];
		if( blocked )	ptr->partOfBlocked = true;
		else ptr->partOfUnblocked = true;
		ptr->prefixes++;
	}
	if( blocked ){
		ptr->blockedWords++;
		ptr->partOfBlocked = true;
	}	
	else{
		ptr->unblockedWords++;
		ptr->partOfUnblocked = true;	
	} 
	sumWords(ptr);
}

void addToSet(){
	if(!st.empty()){
		string str(1,st.top());
		st.pop();
		while(!st.empty()){
			str += st.top();
			st.pop();
		}
		ans.insert(str);
	}
}

void putToStack(node *ptr, node* root){
	node *prev;
	while( !ptr->partOfUnblocked && ptr!=root ){
		prev = ptr;
		ptr = ptr->parent;
	}
	ptr = prev;
	while( ptr != root ){
		st.push(ptr->data);
		ptr = ptr->parent;
	}
	addToSet();
}

void recur( node *a, node *root){
	bool hasChild = false;
	lp(i,26){
		if( a->child[i] != NULL && a->child[i]->partOfBlocked ){
			hasChild = true;
			recur( a->child[i], root);
		}
	}
	if( hasChild == false ){
		putToStack( a, root);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t,n,m,e,a,b,q,h,f,w,k,p;
    ///////////// START FROM HERE ////////////////////
	cin >> n;
	vector<char> c(n);
	string str[n];
	
	node* root = newNode();
	
	lp(i,n){
		cin >> c[i];
		cin >> str[i];
	}
	// inserting blocked strings
	lp(i,n){
		bool check = true;  
		if( c[i] == '-' ){
			insert( root, str[i], true, check);
		}	
	}
	
	// inserting unblocked strings
	lp(i,n){
		bool check = true;
		if( c[i] == '+' ){
			insert( root, str[i], false, check);
		}	
		if( !check ){
			cout << -1 ;
			return 0;
		}
	}	
		
	recur( root, root);
	
	cout << ans.size() << "\n";
	lpit(it,ans)	cout << *it << "\n";
	
	return 0;
}

