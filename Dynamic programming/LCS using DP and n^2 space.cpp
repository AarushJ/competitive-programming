#include<iostream>
using namespace std;

int lcs(string &x,string &y,int m,int n){
	int dp[m+1][n+1];
	for(int i=0 ; i<=m ; i++)	dp[i][0] = 0;
	for(int i=1 ; i<=n ; i++)	dp[0][i] = 0;
	
	for(int i=1 ; i<=m ; i++){
		for(int j=1 ; j<=n ; j++){
			if(x[i]==y[j])	dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	return dp[m][n];
}

int main(){
	string x,y;
	cin >> x >> y;
	int m = x.size() , n = y.size();
	
	cout << lcs(x,y,m,n) ;	
	return 0;
}
