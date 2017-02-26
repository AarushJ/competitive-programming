#include<iostream>
using namespace std;
typedef long long ll;
#define MAX 1000
#define MOD 1000000
ll cat[MAX+1];

ll catalan(){
	cat[0] = 1;
	cat[1] = 1;
	for(int i=2 ; i<=MAX ; i++){
		cat[i] = 0;
		for(int j=0 ; j<i ; j++){
			cat[i] += (((cat[j]%MOD)*(cat[i-j-1]%MOD))%MOD);
			cat[i]%=MOD;
		}
	}
}

int main(){
	catalan();
        int n;
	while(1){
		cin >> n;
		if(n==0) break;
        cout << cat[n] << "\n";
	}
	return 0;
}
