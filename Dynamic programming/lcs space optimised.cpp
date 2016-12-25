#include<iostream>
using namespace std;
 
int lcs(string &x, string &y){
    int m = x.length(), n = y.length();
    int dp[2][n+1];
    bool a;
    for (int i=0; i<=m; i++){
        a = i&1;
        for (int j=0; j<=n; j++){
            if(i == 0 || j == 0)
                dp[a][j] = 0;
            else if (x[i-1] == y[j-1])
                dp[a][j] = dp[1-a][j-1] + 1;
            else
                dp[a][j] = max(dp[1-a][j], dp[a][j-1]);
        }
    }
    return dp[a][n];
}
 
int main(){
	string x,y;
	cin >> x >> y;
    cout << lcs(x,y);
    return 0;
}
