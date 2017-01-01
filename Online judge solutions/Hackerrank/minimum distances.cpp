#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int num[n];
	for(int i=0 ; i<n ; i++){
		cin >> num[i];
	}
	int distance=n;
	int count=0;
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			if(num[i]==num[j]){
				if(abs(i-j)<distance){
					distance=abs(i-j);
					count++;
				}
			}
		}
	}
	if(count){
	cout << distance ;
	}else{
		cout << -1;
	}
	
	return 0;
}
