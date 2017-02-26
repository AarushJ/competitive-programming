#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		int a,b;
		cin >> a >> b;
		int ans=1;
		a=a%10;
		while(b>0){
			if(b%2) ans=(ans*a)%10;
			b/=2;
			a=(a*a)%10;
		}
		cout << ans << endl;
	}
	return 0;
}
