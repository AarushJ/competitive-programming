#include<iostream>
using namespace std;

int main(){
	int n;
	while(1){
		cin >> n;
		if(n!=-1){
			int num[n];
			int sum=0;
			for(int i=0 ; i<n ; i++){
				cin >> num[i];
				sum+=num[i];
			}
			if(sum%n!=0){
				cout << -1 << endl ; 
			}else{
				int candyPerPacket=sum/n,moves=0;
				for(int i=0 ; i<n ; i++){
					if(num[i]<candyPerPacket){
						moves+=(candyPerPacket-num[i]);						
					}
				}
				cout << moves << endl;
			}
			
		}else{
			break;
		}
	}
	return 0;
}
