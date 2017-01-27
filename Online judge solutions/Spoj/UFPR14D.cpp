#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n ;
	int num[n+1];
	long sum=0;
	for(int i=1 ; i<=n ; i++){
		cin >> num[i];
		sum+=num[i];
		num[i]=sum;
	}
	int q;
	cin >> q;
	int a,b;
	for(int i=0 ; i<q ; i++){
		cin >> a >> b;
		if(a==1){
			cout << num[b] << "\n";
		}else{
			cout << num[b]-num[a-1] << "\n";
		}
	}
	return 0;
}
