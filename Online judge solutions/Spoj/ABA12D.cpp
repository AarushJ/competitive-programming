#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,a)	for(ll i = (ll)0 ; i < ll(a) ; i++)
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define all(a) a.begin(),a.end()

vector<ll> squares, nums;
#define MAX 1000001

bool notPrime[MAX];
inline ll fme(ll x,ll n){ll ans=1; while(n>0){if(n&1){ ans*=x;} x*=x;n>>=1;}return ans;}
void prime_sieve(){ for(ll i=2 ; i*i<MAX ; i++){	if(!notPrime[i]){ for(ll j=i*i ; j<=MAX ; j+=i)	notPrime[j] = 1;} } 	}

bool factorize_brute(int n, map<int,int> &mp){
	int numbers = 0;
	ll i = 2;
	ll N = n;
	while( n > 1 && i*i <= N){
		if( n%i == 0 ){
			numbers++;
			if( numbers > 1 )	return false;
			int cnt = 0;
			while( n%i == 0 ){
				cnt++;
				n /= i;
			}
			mp[i] = cnt;
		}
		i++;
	} 

	return true;
}

void precompute(){
	nums.push_back(2);
	for(int i = 2; i<= 10000 ; i++ ){
		if( i*i < MAX ){
			squares.push_back(i*i);
		}else{
			break;
		}
	}
	ll len = squares.size();
	lp(i, len){
		map<int,int> mp;
		if( factorize_brute(squares[i], mp) ){
			map<int,int>::iterator it = mp.begin();
			ll p = (ll)it->first, n = (ll)it->second;
			ll sum = (fme(p,n+1) - 1)/(p-1);
			if( !notPrime[sum] ){
				nums.push_back(squares[i]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,a,b;
	cin >> t;
	prime_sieve();
	precompute();
	while(t--){
		cin >> a >> b;
		int ans = upper_bound(all(nums), b) - lower_bound(all(nums), a);
		cout << ans << "\n";
	}
}