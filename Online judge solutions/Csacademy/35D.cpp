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
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))

//////////////////////////////////////////// CONTAINERS FOR FUNCTIONS MENTIONED IN TEMPLATE ///////////////////////////////////
#define MAX 100005
//bool isPrime[MAX];
//int spf[MAX];

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

ll countEven(ll n){
    ll count = 0;
    while(n){
        if( n%2 == 0){
            count++;
        }
        n /= 10;
    }
    return count;
}

ll makeNum(string &str){
    ll a = 0;
    lpit(it, str){
        int num = *it - '0';
        a = a*10 + num;
    }
    return a;
}

string toString(ll n){
    string str;
    while(n){
        ll num = n%10;
        str.push_back(char(num+'0'));
        n /= 10;
    }
    reverse(all(str));
    return str;
}

ll doMin(ll n){
    int evenInN = countEven(n);
    string str = toString(n);
    int len = str.size();
    ll res = 0;
    // required num => max amongst all "prefix999...99", required num < n and required num has less even digits than n
    ll prefix = 0;
    for(int str_index = 0; str_index < len; str_index++){
        prefix *= 10;
        for(ll digit = 0 ; digit <str[str_index]-'0' ; digit++){
            ll num = prefix + digit;
            for(int i = str_index+1 ; i<len ; i++){
                num *= 10;
                num += 9;
            } 
            if( num < n && countEven(num) < evenInN ){
                res = max( res, num);
            }      
        }
        prefix += str[str_index]-'0';
    }
    return res+1;
}

ll doMax(ll n){
    string str = toString(n);
    int len = str.length();
    for(int i = len-1 ; i>=0 ; i--){
        int a = str[i]-'0';
        if( a%2 == 0 ){
            str[i]++;
            for(int j = i+1 ; j<len ; j++){
                str[j] = '1';
            }
            return makeNum(str)-1;
        }
    }
}

int main(){
    ll t, n, m, v, p, q, k, a, b, c, d, e , f, type, x, y, z;
    cin >> x;
    if( !countEven(x) ){
        cout << -1 << "\n";
    }else{
        //cout << "in else : \n";
        ll a = doMin(x);
        //cout << "a : " << a << "\n";
        ll b = doMax(x);
        //cout << "b : " << b << "\n";
        cout << (x-a+1)*(b-x+1) << "\n";
    }
    return 0;
}
