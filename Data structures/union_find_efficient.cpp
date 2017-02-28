#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define lp(i,a,b)	for(ll i=ll(a) ; i<ll(b) ; i++)

void init(int par[],int sz[],int n){
	lp(i,0,n){
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int par[],int i){
 	while( i != par[i] )	i=par[par[i]];	// path compression
	return i;
}

void merge(int par[],int sz[],int u,int v){
	int a = find(par,u);
	int b = find(par,v);
	if(a==b)	return; // union by rank/size
	if( sz[a] < sz[b] ) { par[a] = b; sz[b]+=sz[a];	}
	else				{ par[b] = a; sz[a]+=sz[b];	}
}

bool areConn(int u,int v,int par[]){
	return (find(par,u)==find(par,v));
}

int main(){
	int n;
	int par[n],sz[n];
	cin >> n;
	init(par,sz,n);
	
	
	// corresponding merge, find and areConn functions...
	
	
	return 0;
}
