#include<cmath>
#include<iostream>
using namespace std;

int main() {
	// your code goes here
	while(1){
		long long n;
		cin >> n;
		if(n){
			int count = 0;
			while(n%2==0){
				count++;
				n/=2;
			}
			
			if(count)
				cout << 2 <<"^" << count << " ";
			
			for(int i=3 ; i<=sqrt(n) ; i+=2){
				if(n%i==0){
					count = 0;
					while(n%i==0){
						count++;
						n/=i;
					}
						cout << i <<"^" << count << " ";
				}	
			}
			if(n>1) cout << n << "^" << 1 ;
			cout << endl;
		}else break;
	}
	return 0;
}
