/*
	AARUSH JUNEJA
	@vivace
	IIT(ISM),Dhanbad
	Topics : Dynamic programming, modular arithmetic
*/

#include<bits/stdc++.h>
using namespace std;

int sub(int a, int b){
	return ((a%100)-(b%100)+100)%100;
}

int cost(int pre[], int i, int j, int k){
	int a = sub(pre[k], pre[i-1]);
	int b = sub(pre[j], pre[k]);
	return a*b;
}

int main(){
	int n;
	while( scanf("%d",&n) != EOF ){
		int arr[n+1], pre[n+1];
		pre[0] = 0;
		for(int i = 1 ; i<=n ; i++){
			scanf("%d", arr + i);
			pre[i] = pre[i-1] + arr[i];
		}
		int dp[n+1][n+1]; // ans dp[1][n]
		
		for(int i = 0 ; i<=n ; i++){
			dp[i][i] = 0;
			dp[0][i] = 0;
			dp[i][0] = 0;
		}
		
		for(int j = 2 ; j <= n ; j++){
			for(int i = j-1 ; i > 0  ; i--){
				dp[i][j] = INT_MAX;
				for(int k = i ; k < j ; k++){
					dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j] + cost(pre,i,j,k) );
				}
			}
		}
		
		cout << dp[1][n] << "\n";
			
	}
	
	return 0;
}
