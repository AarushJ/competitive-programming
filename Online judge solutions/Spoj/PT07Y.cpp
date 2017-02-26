#include <iostream>
#include <cstring>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	public:
	bool *visited;
	Graph(int v);
	void addEdge(int u,int v);
	void dfs();
	void dfsUtil(int v);
};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int> [v+1];
	visited = new bool[v+1];
	for(int i=1 ; i<=v ; i++)	visited[i] = false;
}

void Graph::addEdge(int u,int v){
	adj[u].push_front(v);
	adj[v].push_front(u);
}

void Graph::dfsUtil(int v){
	visited[v] = true;
	list<int>::iterator it;
	for(it = adj[v].begin() ; it!=adj[v].end() ; it++){
		if(!visited[*it]){
			dfsUtil(*it);
		}
	}
}

int main() {
	int n,m;
	cin >> n >>m;
	Graph g(n);
	int u,v;
	for(int i=0 ; i<m ; i++){
		cin >> u >> v;
		g.addEdge(u,v);
	}
	if(n-1!=m){
		cout << "NO";
		return 0;
	}	
	else{
		g.dfsUtil(1);	
	}
	for(int i=1 ; i<=n ; i++){
		if(!g.visited[i]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
