#include<cmath>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef double lf;
typedef long long ll;
typedef long double LF;
typedef unsigned long long ull;
using namespace std;

int ans(int h,int w,int *s,int *sum,int i,int j){
	if(i<0 || i>=h || j<0 || j>=w)	return 0;
	if( *(sum+i*w+j) )	return *(sum+i*w+j);
	*(sum+i*w+j) = max( ans(h,w,s,sum,i-1,j) , max( ans(h,w,s,sum,i-1,j-1) , ans(h,w,s,sum,i-1,j+1) ) ) + *(s+i*w+j);
	return *(sum+i*w+j);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int h,w;
		cin >> h >> w;
		int s[h][w],sum[h][w];
		memset(sum,0,h*w*sizeof(int));
		for(int i=0 ; i<h ; i++){
			for(int j=0 ; j<w ; j++){
				cin >> s[i][j];
			}
		}
		int maximum = INT_MIN;
		for(int j=w-1 ; j>=0 ; j--){
			maximum=max(maximum,ans(h,w,(int*)s,(int*)sum,h-1,j));
		}
		cout << maximum << "\n";
	}
	return 0;
}
