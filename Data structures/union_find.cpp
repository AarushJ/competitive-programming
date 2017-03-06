#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define lp(i,a,b)	for(ll i=ll(a) ; i<=ll(b) ; i++)

#define N 100005
ll n;
ll par[N],sz[N];
void init(){
	lp(i,0,n-1){
		par[i] = i;
		sz[i] = 1;
	}
}

ll find(ll i){
 	while( i != par[i] ){
		par[i] = par[par[i]];	// path compression 
		i = par[i];
	} 	
	return i;
}

void merge(ll u,ll v){
	ll a = find(u);
	ll b = find(v);
	if(a==b)	return; // union by rank/size
	if( sz[a] < sz[b] ) { par[a] = b; sz[b]+=sz[a];	}
	else				{ par[b] = a; sz[a]+=sz[b];	}
}

bool areConn(ll u,ll v){
	return (find(u)==find(v));
}

int main(){
	ll n;
	
	cin >> n;
	init(n);
	
	
	// corresponding merge, find and areConn functions...
	
	
	return 0;
}
