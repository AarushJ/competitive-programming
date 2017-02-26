#include <iostream>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(ll i = ll(a); i<ll(b) ; i++) 

bool isSingle(char c,char s){
	if(10*(c-'0')+s-'0'<= 26 )	return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	while(1){
		cin >> s;
		ll len =(ll) s.size();
		if(s[0] == '0') break;
		ll dp[len+1];
		dp[0] = 1;
		dp[1] = 1;	
		loop(i,1,len){
			if(s[i] == '0' || s[i-1] == '0' || (i!=len-1 && s[i+1]=='0') || isSingle(s[i-1],s[i]))dp[i+1] = dp[i];
			else	dp[i+1] = dp[i]+dp[i-1];		
		}
		cout << dp[len] << "\n";
	}
	return 0;
}
