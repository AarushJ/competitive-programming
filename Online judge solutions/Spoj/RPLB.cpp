#include <iostream>
#include <vector>
using namespace std;

int ans(int n,int k,int val[],vector<vector<int> > &dp){
	if(n < 0)	return 0;
	if(dp[n][k] > -1)	return dp[n][k];
	if(n ==0 || k==0 )
		dp[n][k] = 0;
	else if(val[n-1] > k)	
		dp[n][k] = ans(n-1,k,val,dp);
	else 
		dp[n][k] = max(ans(n-1,k,val,dp),ans(n-2,k-val[n-1],val,dp)+val[n-1] );
	return dp[n][k];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,k;
	cin >> t;
	int i=1;
	while(t--){
		cin >> n >> k;
		vector<vector<int> > v(n+1,vector<int>(k+1,-1));
		int val[n];
		for(int i=0 ; i<n ; i++)
			cin >> val[i];
		cout << "Scenario #" << i <<": " << ans(n,k,val,v) << "\n"; 
		++i;		 
	}
	return 0;
}
