#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin >> n >> m;
    int arr[m];
    for(int i=0 ; i<m ; i++)    cin >> arr[i];
    sort(arr,arr+m);
    long long int t[m+1][n+1];
    
    for(int i=0 ; i<=m ; i++)   t[i][0] = 1;
    for(int i=0 ; i<=n ; i++)   t[0][i] = 0;   
        
	for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            if(j >= arr[i-1] ){
                t[i][j] = t[i-1][j] + t[i][(j-arr[i-1])];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    cout << t[m][n];
    return 0;
}
