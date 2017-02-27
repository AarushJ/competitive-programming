#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

bool flag;

void dfs(list<int> g[],int v,int mark[],int col[],int prevCol){
	mark[v] = true;
	//cout << v << "marked true \n";
	int currCol;
	if(prevCol==1)	currCol = -1;
	else currCol = 1;	
	
	list<int>::iterator it;
	for( it=g[v].begin() ; it!=g[v].end() ; it++){
		if(!mark[*it]){
			col[*it] = currCol;
			dfs(g,*it,mark,col,currCol);
		}else{
			if(col[*it]==prevCol){
				flag = false;
				return;
			}
		}
		if(!flag)	return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	cin >> t;
	for(int j=1 ; j<=t ; j++){
		flag = true;
		int v,e,a,b;
		cin >> v >> e;
		int mark[v],col[v];
		memset(mark,0,sizeof(mark));
		memset(col,0,sizeof(col));
		list<int> g[v];
		for(int i=0; i<e ; i++){
			cin >> a >> b;
			g[a-1].pb(b-1);
			g[b-1].pb(a-1);
		}
		col[0] = 1;
		for(int i=0 ; i<v ; i++){ if(!mark[i])	dfs(g,i,mark,col,1); }
		if(flag){
			cout << "Scenario #" << j << ":\n" << "No suspicious bugs found!\n" ; 
		}else{
			cout << "Scenario #" << j << ":\n" << "Suspicious bugs found!\n" ;
		}
	}
	return 0;
}
