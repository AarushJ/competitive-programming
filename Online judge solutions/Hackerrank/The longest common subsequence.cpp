#include<cmath>
#include<stack>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
double lf;
typedef long long ll;
typedef long double LF;
typedef unsigned long long ull;
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> x(n+1),y(m+1);
	for(int i=1 ; i<=n ; i++)	cin >> x[i];
	for(int i=1 ; i<=m ; i++)	cin >> y[i];
	
	int t[m+1][n+1];
	for(int i=0 ; i<=m ; i++)	t[i][0] = 0;
	for(int i=1 ; i<=n ; i++)	t[0][i] = 0;
	
	for(int i=1 ; i<=m ; i++){
		for(int j=1 ; j<=n ; j++){
			if(x[j]==y[i])	t[i][j] = ++t[i-1][j-1];
			else t[i][j] = max(t[i-1][j],t[i][j-1]);
		}
	}
	stack<int> lcs;
	int i=m,j=n;
	while(i > 0 && j > 0 ){
		if(y[i]==x[j]){
    		lcs.push(y[i]);
    		i--;
    		j--;
		}else{
			if(t[i-1][j]==t[i][j-1])	j--;
			else if(t[i-1][j] > t[i][j-1]) i--;
			else j--;
		}
	}
	while(!lcs.empty()){
		cout << lcs.top() << " ";
		lcs.pop();
	}
	return 0;
}
