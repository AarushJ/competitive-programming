#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define loop(i,a,b) for(int i = int(a); i<int(b) ; i++)
#define MAX 10000000
bool prime[MAX+1];			// due to global declaration , all elements will be set to false by default 
							// prime[i] = false indicates prime 
void sieve(){	   			// no need of memset because isPrime is global 
	int root = sqrt(MAX);
	loop(i,2,root+1){
		if(!prime[i]){ 
			for( int j = i*i ; j<=MAX ; j+=i )
				prime[j] = true; 
		}
	}
}

int main(){
	sieve();
	loop(i,2,500){
		if(!prime[i])
			cout << i << " ";
	}
	return 0;
}
