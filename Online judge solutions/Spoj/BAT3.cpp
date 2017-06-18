#include<bits/stdc++.h>
using namespace std;

#define lp(i,a)	for(int i = (int)0 ; i < int(a) ; i++)

int dp[1005], arr[1005];

int main(){
	int t, n, m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		lp(i,n)	scanf("%d",&arr[i]), dp[i] = 1;
		dp[0] = 1;
		for(int i = 1 ; i < n ; i++){
			for(int j = 0 ; j < i ; j++){
				if( arr[j] > arr[i] || j == m )
					dp[i] = max( dp[i], dp[j] + 1);
			}
		}
		
		int maxx = 1;
		lp(i,n)
			maxx = max( maxx, dp[i]);
		printf("%d\n", maxx);
	}
}