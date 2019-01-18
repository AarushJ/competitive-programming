#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int k;
	while(1){
		cin >> k;
		if( !k ) break;
		string a, b;
		cin >> a >> b;
		int n = a.size(), m = b.size();
		int dp[n+1][m+1];
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= m ; j++){
				dp[i][j] = 0;
			}
		}
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				int c = 1;
				while( i-c>=0 && j-c>=0 && a[i-c]==b[j-c] ){
						if( c >= k ){
							dp[i][j] = max(dp[i][j], dp[i-c][j-c]+c);
						}
						c++;
					}
					if( i>=1 ) dp[i][j] = max(dp[i][j], dp[i-1][j]);
					if( j>=1 ) dp[i][j] = max(dp[i][j], dp[i][j-1]); 
			}
		}
		
	
		
		cout << dp[n][m] << "\n";
	}
	return 0;
} 