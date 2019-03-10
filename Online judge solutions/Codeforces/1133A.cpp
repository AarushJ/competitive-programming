#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i, b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpp(i, a, b) for(ll i = ll(a); i<ll(b) ; i++) 

ll MOD = 1e9 + 7;

inline ll fmm(ll a,ll b,ll m=MOD) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}return r%m;}
inline ll fme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1){r*=a;r%=m;}a*=a;a%=m;b>>=1;}return r%m;}
inline ll sfme(ll a,ll b,ll m=MOD) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}return r%m;}

ll h1, h2, m1, m2;
char ch;
string str;

ll util(char ch){
	return ch-'0';
}

int main(){
	cin >> str;
	h1 = util(str[0])*10 + util(str[1]);
	m1 = util(str[3])*10 + util(str[4]);
	cin >> str;
	h2 = util(str[0])*10 + util(str[1]);
	m2 = util(str[3])*10 + util(str[4]);
	ll min1 = h1*60 + m1;
	ll min2 = h2*60 + m2;

	ll m = (min1 + min2)/2;
	ll hh = m/60, mm = m%60;

	if( hh < 10 )	cout << "0";
	cout << hh << ":";
	if( mm < 10 )	cout << "0";
	cout << mm << "\n";

	
	

}