#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define gc getchar
#define lp(i,a,b) for(int i = int(a); i<int(b) ; i++) 

ll ip(){
	ll x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc() )	x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t,n;
	cin >> t;
	lp(i,1,t+1){
		cin >> n;
		int coins[n],dp[n+1];
		lp(i,0,n)	cin >> coins[i];
		dp[0] = 0;
		dp[1] = coins[0];
		lp(i,2,n+1){
			dp[i] = max(dp[i-1],coins[i-1]+dp[i-2]);
		}
		cout << "Case " << i << ": " << dp[n] << "\n"; 
	}
	return 0;
}


