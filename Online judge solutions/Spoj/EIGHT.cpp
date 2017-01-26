#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		long long k;
		cin >> k;
		long long int j=1;
		int arrForKLessThan5[4]={192,442,692,942};
		int arrForKGreaterThan4[4]={942,192,442,692};
		if(k<=4){
			cout << arrForKLessThan5[k-1] << endl;		
		}else{
			long long j=(k%4)?(k/4):(k/4-1);
			cout << j << arrForKGreaterThan4[k%4] << endl;
		}
	}
	return 0;
}
