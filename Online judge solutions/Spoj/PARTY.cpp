#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,w; // w is max budget
	cin >> w >> n;
	while(n!=0 && w!=0){
		int cost[n],fun[n];
		int dp[n+1][w+1];
		for(int i=0 ; i<n ; ++i)
			cin >> cost[i] >> fun[i];
			
		for(int i=0 ; i<=n ; ++i){
			for(int j=0 ; j<=w ; ++j){
				if(i==0 || j==0)
					dp[i][j] = 0;
				else if(cost[i-1] > j)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-cost[i-1]] + fun[i-1]);
			}
		}
		int ans;
		for(int j=0 ; j<=w ; ++j){
			if(dp[n][w]==dp[n][j]){
				ans = j ;
				 break;
			}
		}
		cout << ans << " " << dp[n][w] << "\n";
		cin >> w >> n;
	}
	return 0;
}
