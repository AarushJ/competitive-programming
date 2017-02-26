#include <iostream>
#include <cmath>
using namespace std;
#define loop(i,a,b) for(int i=(int)a ; i<(int)b ; i++)
typedef long long ll;
ll knap(int wt[],int val[],int k,int m){
	ll dp[m+1][k+1];
	loop(i,0,m+1)	dp[i][0] = 0;
	loop(i,0,m+1){
		loop(j,1,k+1){
			if( i==0 || k==0 )
						dp[i][j] = 0;
			else if(wt[i-1] > j )
						dp[i][j] = dp[i-1][j]; 
			else 
						dp[i][j] = max( dp[i-1][j] ,dp[i-1][j-wt[i-1]]+val[i-1] );
		}
	}
	
	return dp[m][k];
}

int main() {
	int t;
	cin >> t;
	int k,m;
	while(t--){
		cin >> k >> m;
		int wt[m],val[m];
		loop(i,0,m)
					cin >> wt[i] >> val[i];
		cout << "Hey stupid robber, you can get " << knap(wt,val,k,m) << ".\n";
	}
	return 0;
}
