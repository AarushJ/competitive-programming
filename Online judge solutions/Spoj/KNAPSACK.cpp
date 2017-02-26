#include<vector>
#include<iostream>
using namespace std;
int f(int n,int w,int *dp,vector<int> &wt,vector<int> &val,int N,int W){
	if(*(dp+W*n+w)>=0)	return *(dp+W*n+w);
	if(n==0 || w ==0 )	return 0;
	if(wt[n] > w)	*(dp+W*n+w)= f(n-1,w,dp,wt,val,N,W);
	else{
		*(dp+W*n+w) = max( f(n-1,w,dp,wt,val,N,W), f(n-1,w-wt[n],dp,wt,val,N,W) + val[n]);
	}
	return *(dp+W*n+w);
}

int main(){
	int s,n;
	cin >> s >> n;
	vector<int> wt(n),val(n);
	for(int i=0 ; i<n ; i++)	cin >> wt[i] >> val[i];
	int dp[n][s+1];
	for(int i=0 ; i<n ; i++) dp[i][0] = 0;
	for(int i=0 ; i<n ; i++){
		for(int j=1 ; j<=s ; j++){
			dp[i][j] = -1;
		}
	}
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<=s ; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << f(n-1,s,(int*)dp,wt,val,n,s+1) << endl;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<=s ; j++){
			cout << dp[i][j] << " ";
		}
			
		cout << "\n";
	}
	return 0;
}
