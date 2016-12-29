#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		int n,c,m;
		cin >> n >>c >>m ;
		int count=0,wrappers=0;
		while(n>=c){
			wrappers+=n/c;
			count+=n/c;
			while(wrappers>=m){
				count+=wrappers/m;
				wrappers=wrappers/m+wrappers%m;
			}
			n=(n%c);	
		}
		cout << count << endl;
	}
	return 0;
}
