#include<iostream>
#include<cmath>
using namespace std;

int total(int sum[],int low,int high){
	if(high==low) return 0;
	int points = 0;   
	int j=low-1;
	for(int i=low ; i<=high ; i++){
		if( (((i==0)?sum[0]:sum[i]-sum[j])) == (sum[high]-sum[i]) ){
			points++;
			points += max( total(sum,low,i) , total(sum,i+1,high) );
			break;
		}
	}
	return points;
}

int main(){
	int t;
	cin >> t;
	int n;
	while(t--){
		cin >> n;
		int n1=n;
		int sum[n];
		cin >> n ;
		sum[0] = n;
		for(int i=1 ; i<n1 ; i++){
			cin >> n;
			sum[i] = sum[i-1]+n;
		}
		int points = total(sum,0,n1-1);
		cout << points << "\n";
	}
	return 0;
}
