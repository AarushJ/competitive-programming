#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ll n;
    cin >> n;
    ll arr[n][n];
    vll row(n), col(n);
    ll maxx = -1;
    lp(i, n){
    	lp(j, n){
    		cin >> arr[i][j];
    		row[i] += arr[i][j];
    		col[j] += arr[i][j];
    	}
    }    
    
    lp(i, n){
    	maxx = max(maxx, row[i]);
    	maxx = max(maxx, col[i]);
    }
    //cout << "maxx : " << maxx << "\n";
    lp(i, n){
    	//cout << "i : " << i << "\n";
    	ll need = maxx-row[i];
    	//cout << "need : " << need << "\n";
    	lp(j, n){
    		if( need == 0 )		break;
    		if( col[j] == maxx )	continue;
    		if( col[j] + need > maxx){
    			arr[i][j] += maxx - col[j];
    			need -= maxx-col[j];
    			col[j] = maxx;
    		}else{
    			arr[i][j] += need;
    			col[j] += need;
    			row[i] = maxx;
    			need = 0;
    		}
    	}
    }
    lp(i, n){
    	lp(j, n){
    		cout << arr[i][j] << " ";
    	}
    	cout << "\n";
    }
    cout << "\n";
    return 0;
}