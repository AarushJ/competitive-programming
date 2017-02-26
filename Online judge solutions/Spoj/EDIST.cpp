#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string str1,str2;
	cin >> t;
	while(t--){
		cin >> str1 >> str2;
		int a = str1.size(), b = str2.size();
		if(a > b){
			string temp = str2;
			str2 = str1;
			str1 = temp;
			a = str1.length() ; 
			b = str2.length() ;
		}
		int dp[a+1][b+1];
		for(int i=0 ; i<=a ; i++)	dp[i][0] = i;
		for(int j=0 ; j<=b ; j++)	dp[0][j] = j;
		
		for(int i=1 ; i<=a ; i++){
			for(int j=1 ; j<=b ; j++){
				if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
				else{
					dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
				}
			}
		}			
		cout << dp[a][b] << "\n";
	}
	return 0;
}
