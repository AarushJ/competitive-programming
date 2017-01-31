#include <bits/stdc++.h>
using namespace std;

int lcs(string &s){
	string t;
	t.resize(s.length());
	reverse_copy(s.begin(),s.end(),t.begin());
	//cout << s << endl << t << endl;
	int dp[s.length()+1][t.length()+1];
	int n = s.length();
	for(int i=0 ; i<=n ; i++){
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(s[i-1]==t[j-1])	dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	}
	//cout << "dp " << dp[n][n] << endl;
	return dp[n][n];
	
}

int main() {
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << s.length() - lcs(s) << "\n";
	}
	return 0;
}
