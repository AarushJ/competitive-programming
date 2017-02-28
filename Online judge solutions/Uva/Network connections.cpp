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
	int t,n,u,v;
	char ch;
	string s;
	cin >> t;
	while(t--){
		scanf("%d",&n); getchar();
		int par[n],sz[n];	
		init(par,sz,n);
		
		int succ = 0,unsucc = 0;
		while( (ch=getchar()) && isalpha(ch) ){
			cin >> u >> v; getchar(); 
			if(ch=='c') merge(par,sz,u,v);
			else{
				if(areConn(u,v,par))	++succ;
				else ++unsucc;
			}
						
		}
		cout << succ << "," << unsucc << "\n\n";
	}
	
	return 0;
}
