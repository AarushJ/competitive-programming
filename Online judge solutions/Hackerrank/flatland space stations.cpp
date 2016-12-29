#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n>>m;
	int c[m];
	for(int i=0 ; i<m ; i++){
		cin >> c[i];
	}
	
	sort(c,c+m);
	int maximum=0;
	int maxStart=c[0];
	int maxEnd=n-1-c[m-1];
	int diff=0;
	for(int i=0 ; i<=m-2 ; i++){
		diff=c[i+1]-c[i];
        if(((diff%2)?(diff+1/2):diff/2 )> maximum){
			maximum=((diff%2>1)?(diff+1)/2:diff/2);
		}
	}
	cout << max(maximum,max(maxStart,maxEnd));
	return 0;
}
