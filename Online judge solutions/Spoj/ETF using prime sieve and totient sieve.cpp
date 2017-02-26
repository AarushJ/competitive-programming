#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000000
int phi[MAX+1];
bool isPrime[MAX+1];

void sieve(){
	int root = sqrt(MAX);
	for(int i=2 ; i<=root ; i++){
		if(!isPrime[i]){
			for(int j=i*2 ; j<=MAX ; j+=i){
				isPrime[j] = true;
			}
		}
	}
}

void etf(){
	for(int i=1 ; i<=MAX ; i++)	phi[i] = i;
	for(int i=2 ; i<=MAX ; i++){
		if(!isPrime[i]){
			for(int j=i ; j<=MAX ; j+=i){
				phi[j] -= phi[j]/i;
			}
		}
	}
}

int main() {
	sieve();
	etf();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << phi[n] << "\n";
	}
	return 0;
}
