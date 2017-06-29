#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 100010

typedef double lf;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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

//////////////////////////////////////////// CONTAINERS FOR FUNCTIONS MENTIONED IN TEMPLATE ///////////////////////////////////
#define MAX 100005
//bool isPrime[MAX];
//int spf[MAX];

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

int main(){
	ll t, n, m, v, p, q, k, a, b, c, d, e , f, type, x, y, z;
	cin >> n;
	vll arr(n), ans(n);
	lp(i ,n)    cin >> arr[i];
	ll beg = 0, end = 0;

	for(int i = 0 ; i<n-1 ; i++){
		if( arr[i] > arr[i+1] ){
			end++;
		}else{
			for(int j = beg ; j<=end ; j++){
				ans[j] = end-beg+1;
			}
			beg = i+1;
			end = i+1;
		}
	}	

	lp(i, n){
		if( !ans[i] ){
			ans[i] = end-beg+1;
		}
	}	
	lp(i, n)	cout << ans[i] << " "; cout << "\n";

	return 0;
}
