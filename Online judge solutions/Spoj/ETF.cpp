#include<iostream>
#include<cmath>
using namespace std;           // 4
							   // 4(1/2)
int phi(int n){
	int result = n;
	bool flag = false;
	while(n%2==0){
		flag = true;
		n /= 2;
	}
	
	if(flag)
	 result -=result/2;
	
	int root = sqrt(n);
	for( int i=3 ; i<=root ; i+=2 ){
		flag = false;
		if(n%i==0){
			flag = true;
			while(n%i==0){
				n = n/i;
			}
		}
		if(flag) 
			result -= result/i;
	}
	if(n>1){
		result -= result/n;
	}
	return result;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n ;
		cin >> n ;
		cout << phi(n) <<"\n";	
	}
	
	return 0;
}
