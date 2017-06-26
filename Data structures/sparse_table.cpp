#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define sl(a) scanf("%lld",&a)
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define all(a) a.begin(),a.end()

#define NMAX 100005
#define LOGNMAX 16

ll table[NMAX][LOGNMAX+1];
vll arr(NMAX);

void build_sparse(int n){
	// sparse table template for range sum query
	lp(i, n)	table[i][0] = arr[i];
	for(int j = 1 ; j <= LOGNMAX ; j++){
		for(int i = 0 ; i <= n - (1 << j) ;  i++){
			table[i][j] = table[i][j-1] + table[i + (1 << (j-1))][j-1];
		}	
	}
	
}

ll query_sparse(int qlo, int qhi){
	ll sum = 0, l = qlo, r = qhi;
	for(int j = LOGNMAX ; j>=0 ; j--){
		if( l + (1<<j) - 1 <= r ){
			sum += table[l][j];
			l += (1<<j);
		}
	}
	return sum;
}

int main(){
	int n, q, qlo, qhi;
	cin >> n;
	lp(i, n)	cin >> arr[i];
	build_sparse(n);
	cin >> q;
	while(q--){
		cin >> qlo >> qhi;
		qlo--; qhi--; // assuming query indices are 1-indexed and my sparse table is zero indexed
		ll result = query_sparse(qlo, qhi);
		cout << result << "\n";
	}
}