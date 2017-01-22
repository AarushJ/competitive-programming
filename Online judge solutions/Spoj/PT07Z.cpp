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
#define lp(i,a,b) for(int i = int(a); i<int(b) ; i++) 
#define itvll(c,it) for(vll::iterator it = c.begin() ; it!=c.end() ; it++)
#define itmll(c,it) for(mll::iterator it = c.begin() ; it!=c.end() ; it++)
#define itmsl(c,it) for(msl::iterator it = c.begin() ; it!=c.end() ; it++)

ll ip(){
	ll x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc() )	x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}

#include<bits/stdc++.h>
using namespace std;

class graph{
	int v;
	int *dp1,*dp2;
	list<int> *adj;
	vector<bool> visited;
	public:
		graph(int v);
	   // ~graph();
		void addEdge(int u,int v);
		void dfs1(int s);
		void dfs2(int s);
		int farthest1();
		int farthest2();
		void clear();
};

graph::graph(int v){
	this->v = v;
	adj = new list<int> [v+1];
	visited.resize(v+1,false);
	dp1 = new int[v+1];
	dp2 = new int[v+1];
}

/*graph::~graph(){
	delete dp1;
	delete dp2;
	delete adj;
}            */

void graph::addEdge(int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void graph::dfs1(int s){
	dp1[s] = 0;
	stack<int> st;
	int aux;
	st.push(s);
	while(!st.empty()){
		aux = st.top();
		visited[aux] = true;
		st.pop();
		list<int>::iterator it;
		for(it = adj[aux].begin() ; it!=adj[aux].end() ; it++){
			if(!visited[*it]){
				dp1[*it] = dp1[aux]+1;
				st.push(*it);
			}
		}
	}
}

int graph::farthest1(){ // returns index of farthest
	int index,maxx = -1;
	lp(i,1,v+1){
		if(maxx < dp1[i]){
			maxx = dp1[i];
			index = i;	
		}
	}	
	return index;
}

int graph::farthest2(){
	int maxx = -1;
	lp(i,1,v+1)		maxx = max(maxx,dp2[i]);
	return maxx;
}

void graph::dfs2(int s){
	dp2[s] = 0;
	stack<int> st;
	int aux;
	st.push(s);
	while(!st.empty()){
		aux = st.top();
		visited[aux] = true;
		st.pop();
		list<int>::iterator it;
		for(it = adj[aux].begin() ; it!=adj[aux].end() ; it++){
			if(!visited[*it]){
				dp2[*it] = dp2[aux]+1;
				st.push(*it);
			}
		}
	}
}

void graph::clear(){
	for(int i=0 ; i<=v ; i++)	visited[i] = false;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,u,v;
	cin >> n;
	graph g(n);
	lp(i,0,n-1){
		cin >> u >> v;
		g.addEdge(u,v);
	}                   
	g.dfs1(1);
	int maxx = g.farthest1();
	g.clear();
	g.dfs2(maxx);
	cout << g.farthest2();	
	return 0;
}                                   
