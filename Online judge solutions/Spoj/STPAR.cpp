#include<iostream>
#include<climits>
using namespace std;

int main(){
	int n;
	while(1){
		cin >> n;
		if(n){
			int num[n];
			for(int i=0 ; i<n ; i++) cin >> num[i];
			int count = 0;
			int num_on_top=INT_MAX;
			for(int i=0 ; i<n-1 ; i++){
				if(num[i])
			}
			if(count) cout << "no\n";
			else cout << "yes\n";
		}else break;
	}
	return 0;
}
