#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		long long t3,t3rdLast,sum;
		cin >> t3 >> t3rdLast >> sum;
		long long n=(2*sum)/(t3+t3rdLast);
		long long d=(t3rdLast-t3)/(n-5);
		cout << n <<"\n";
		long long a=t3-2*d;
		for(int j=0 ; j<n ; j++){
			cout << a+(j)*d <<" ";
		}
		cout <<"\n";
	}
	return 0;
}

