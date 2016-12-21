#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i,a,b) for(int i = ll(a); i<=ll(b) ; i++)


ll f(int n,int w,vector<ll> &wt,vector<ll> &val){
	ll dp[n+1][w+1];
	lp(i,0,n) dp[i][0] = 0;
	lp(i,0,n){
		lp(j,1,w){
			if(i==0||w==0)	dp[i][j] = 0;
			else if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j] , dp[i-1][j-wt[i-1]]+val[i-1]);
		}
	}
	return dp[n][w];
}

int main(){
	int s,n;
	cin >> s >> n;
	vector<ll> wt(n),val(n);
	lp(i,0,n-1) cin >> wt[i] >> val[i];
	cout << f(n,s,wt,val);
	return 0;	
}
