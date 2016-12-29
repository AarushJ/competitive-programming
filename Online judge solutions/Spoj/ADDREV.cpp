#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i=0 ; i<n ; i++){
		int a,b,rev_a=0,rev_b=0;
		cin >> a >> b ;
		while(a!=0){
			rev_a=rev_a*10 + a%10;
			a/=10;
		}
		while(b!=0){
			rev_b=rev_b*10 + b%10;
			b/=10;
		}
		int sumOfRev=rev_a+rev_b;
		int sum=0;
		while(sumOfRev!=0){
			sum=sum*10+sumOfRev%10;
			sumOfRev/=10;
		}
		cout << sum << endl;
	}
	return 0;
}
