/* 
	Disjoint set union 

	=> 0-indexed
	=> implemented path compression and union by rank
	=> O(logn) per mergeit/find/areConnected   functions
*/

typedef long long ll;

#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 
#define NMAX 100005

ll n;
ll par[NMAX], rank[NMAX];

void init(ll n){
	lp(i,n){
		par[i] = i;
		rank[i] = 0;
	}
}

ll find(ll i){
 	while( i != par[i] ){
		par[i] = par[par[i]];	// path compression 
		i = par[i];
	} 	
	return i;
}

void mergeit(ll u,ll v){
	ll a = find(u);
	ll b = find(v);
	if(a==b)	return; // union by rank/size
	if( rank[a] < rank[b] ) swap(a, b);
	else if( rank[a] == rank[b] )	++rank[a];
	par[b] = a;
}

bool areConnected(ll u,ll v){
	return (find(u)==find(v));
}

