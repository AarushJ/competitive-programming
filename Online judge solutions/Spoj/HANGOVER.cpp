#include<iostream>
using namespace std;

int main(){
	float c;
	while(1){
		cin >> c;
		if(c==0) break;
		int count=0;
		float sum=0;
		for(float i=2.0 ; 1 ; i++){
			sum+=(1/i);
			count++;
			if(sum>=c) break;
		}
		cout << count <<" card(s)" << endl;
	}
	return 0;
}
