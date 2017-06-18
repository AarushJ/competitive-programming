#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum[2005][2005], arr[2005][2005], dp[1005][1005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll n,m,q,k;	// k -> knapsack capacity
	cin >> n >> m >> q >> k;
	for(int j = 1 ; j<=m ; j++){
		cin >> arr[1][j];
		sum[1][j] = sum[1][j-1] + arr[1][j];
	}
	for(int i = 2 ; i<=n ; i++){
		ll a = 0;
		for(int j = 1 ; j<=m ; j++){
			cin >> arr[i][j];
			a += arr[i][j];
			sum[i][j] = sum[i-1][j] + a;
		}
	}
	
	ll val[q+1], wt[q+1];
	int x1,x2,y1,y2;
	for(int i = 1 ; i<=q ; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		val[i] = (x2-x1+1)*(y2-y1+1);
		wt[i] = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
	}
	
	for(int i = 1; i<=q ; i++){
		for(int j = 1 ; j<=k ; j++){
			if( wt[i] > j )	dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i]] + val[i]);
		}
	}

	cout << dp[q][k] << "\n";
	
	return 0;
}