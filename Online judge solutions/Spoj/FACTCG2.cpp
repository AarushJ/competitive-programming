#include <iostream>
using namespace std;
#define MAX 10000001

int sp[MAX];
bool isPrime[MAX];

bool sp_sieve(){
	for(int i=2 ; i<MAX ; i+=2)	sp[i] = 2;
	for(int i=3 ; i<MAX ; i+=2){
		if(!isPrime[i]){
			sp[i] = i;
			for(long long j=i ; (j*i)<MAX ; j+=2){
				if(!isPrime[i*j])	isPrime[i*j] = true , sp[i*j] = i;
			}
		}
	}
}

int main(){
	sp_sieve();
	
	int n;
	
	while(scanf("%d",&n)!=EOF){
		cout << 1 ;
		while(n!=1){
			printf(" x %d",sp[n]);
			n/=sp[n];
		}
		printf("\n");
	}
	
	return 0;
}
