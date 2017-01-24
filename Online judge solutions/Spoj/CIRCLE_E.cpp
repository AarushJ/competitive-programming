#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		double r1,r2,r3;
		cin >> r1 >> r2 >> r3 ;
		double a = r1*r2 + r2*r3 + r3*r1;
		double b = r1*r2*r3;
		double c = r1+r2+r3;
		printf("%0.6f\n",(b / (a + (2 * sqrt(b*c) ) ) ) );
	}
	return 0;
}
