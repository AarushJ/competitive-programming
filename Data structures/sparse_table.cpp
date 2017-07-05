/* ZERO-INDEXED SPARSE TABLE FOR RANGE SUM QUERY PROBLEM WITHOUT UPDATES*/

typedef long long ll;
typedef vector<ll> vll;

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

