#include<cmath>
#include<cstdio>
#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int s1[n+1],s2[m+1];
    for(int i=1 ; i<=n ; i++)	cin >> s1[i];
    for(int i=1 ; i<=m ; i++)	cin >> s2[i];
    int t[m+1][n+1];
   
    for(int i=0 ; i<=n ; i++)   t[0][i] = 0;
    for(int i=0 ; i<=m ; i++)   t[i][0] = 0;
    
    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            if(s2[i]==s1[j])	t[i][j] = t[i-1][j-1]+1;
            else t[i][j] = max(t[i][j-1],t[i-1][j]);
        }
    }
    
    int i=m,j=n;
    stack<int> lcs;
    while(i>0 && j>0){
    	if(s2[i]==s1[j]){
    		lcs.push(s2[i]);
    		i--;
    		j--;
		}	
    	else{
    		if(t[i-1][j] == t[i][j-1])	j--;
    		else if(t[i][j-1] > t[i-1][j])	j--;
    		else i--;
		}
	}
	while(!lcs.empty()){
		cout << lcs.top() << " ";
		lcs.pop();
	}	
    return 0;
}

