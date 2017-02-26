#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000
int phi[MAX+1];		// for precomputation
int depth[MAX+1];	// for precomputation

void etfs(){ // precomputation
	for(int i=1 ; i<=MAX ; i++)	phi[i] = i;
	for(int i=2 ; i<=MAX ; i++){
		if(phi[i]==i){
			for(int j=i ; j<=MAX ; j+=i){
				phi[j] -= phi[j]/i;
			}
		}
	}
}

void depthCalc(){ // precomputation
	depth[1] = 0;
	for(int i=2 ; i<=MAX ; i++){
		depth[i] = depth[phi[i]]+1;
	}
}

int main() {
	etfs();
	depthCalc();
	vector<int> v[20];
	for(int i=1 ; i<=MAX ; i++){
		if(depth[i] < 20)	v[depth[i]].push_back(i);
	} // precomputation ends here
	int t,m,n,k;
	cin >> t;
	while(t--){
		cin >> m >> n >> k;
		vector<int>::iterator lb,ub;
		lb = lower_bound(v[k].begin(),v[k].end(),m);
		ub = upper_bound(v[k].begin(),v[k].end(),n);
		cout << (ub-lb) << "\n";
	}
	return 0;
}
