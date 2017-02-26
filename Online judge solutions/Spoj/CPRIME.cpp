#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100000000
bitset<MAX+1> isPrime;
int arr[MAX+1];
void sieve(){
	int root = sqrt(MAX);
	for(int i=2 ; i<=root ; ++i){
		if(!isPrime[i]){
			for(int j=i*i ; j<=MAX ; j+=i )
				isPrime[j] = 1;
		}
	}
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	for(int i=3 ; i<=MAX ; i++){
		if(isPrime[i] == 0)
			arr[i] = arr[i-1]+1;
		else 
			arr[i] = arr[i-1];
	}
}

int main(){
	sieve();
	int n;
	while(1){
		scanf("%d",&n);
		if(!n)	break;
		//float pix = (upper_bound(arr.begin() , arr.end() , n) - arr.begin()+1);
		printf("%.1f\n",100*abs((arr[n] - (float)n/log(n) ))/(float)arr[n] );
	}
	return 0;
}
