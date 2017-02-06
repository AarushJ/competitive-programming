#include<bits/stdc++.h>
using namespace std;

typedef double lf;
typedef long long ll;
typedef long double LF;
typedef unsigned long long ull;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef map<string,ll> msl;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef map<ll,ll> mll;

#define gc getchar
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define lp(i,a,b) for(int i = int(a); i<int(b) ; i++) 
#define itvll(c,it) for(vll::iterator it = c.begin() ; it!=c.end() ; it++)
#define itmll(c,it) for(mll::iterator it = c.begin() ; it!=c.end() ; it++)
#define itmsl(c,it) for(msl::iterator it = c.begin() ; it!=c.end() ; it++)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()

ll ip(){
	ll x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc() )	x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}

int main(){
    ll u,p,b,total,val;
    cin >> u >> p >> b;
    vll usb,ps2;
    cin >> total;
    string s;
    lp(i,0,total){
        cin >> val >> s;
        if(s[0]=='U')   usb.pb(val);
        else ps2.pb(val);
    }
    usb.pb(INT_MAX) , ps2.pb(INT_MAX); // sentinel
    sort(all(usb));
    sort(all(ps2));
    ll ans = 0 , count = 0;
    ll l = 0,r = 0 ;
    ll us = usb.size()-1 , ps = ps2.size()-1;
    ll i = 0;
    while(total && u && i<us){
        count++; total--; u--; ans += usb[i++];
    }
    l = i; 
    i = 0;
    while(total && p && i<ps){
        count++ ; total--; p--; ans += ps2[i++];
    }
    r = i;
    while(total && b){
        count++ ; b--; total-- ;
        if(usb[l] < ps2[r]){
            ans += usb[l++];
        }else{
            ans += ps2[r++];
        }
    }
    cout << count <<  " " << ans << "\n";
    return 0; 
}
