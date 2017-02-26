#include <iostream>
using namespace std;
#define MAX 1000000
int phi[MAX+1];

void etf(){
	for(int i=1 ; i<=MAX ; i++)	phi[i] = i;
	for(int i=2 ; i<=MAX ; i++){
		if(phi[i]==i){
			for(int j=i ; j<=MAX ; j+=i){
				phi[j] -= phi[j]/i;
			}
		}
	}
}

int main() {
	etf();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << phi[n] << "\n";
	}
	for(int i=1 ; i<=MAX ; i++)	cout << phi[i] << " ";
	return 0;
}
