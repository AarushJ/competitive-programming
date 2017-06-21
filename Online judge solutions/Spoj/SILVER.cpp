#include<bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	while( 1 ){
		double n;
		cin >> n;
		if( !n )	break;
		cout << int(log2(n)) << "\n";
	}

	return 0;
}
