#include<iostream>
#include<algorithm>
using namespace std;

int dp[5005][5005];

int main(){
	//ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s,r;
	cin >> s;
	
	r = s;
	
	reverse( r.begin() , r.end() );
	
	
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1; j<=n ; j++){
			if(s[i-1]==r[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	
	cout << n - dp[n][n] << "\n";
	
	return 0;
}
