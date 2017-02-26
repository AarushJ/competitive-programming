#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 100000000
vector<bool> prime(MAX+1);
unsigned arr[5000000];
	
void sieve(){
	int root = sqrt(MAX);
	for(int i=2 ; i<=root ; i++){
		if(!prime[i]){
			for(int j=i*i ; j<=MAX ; j+=i)
				prime[j] = true;
		}
	}
	int index = 0;
	int i=3;
	arr[index++] = 2;
	while(index < 5000000 && i<=MAX){
		if(!prime[i]){
			arr[index] = i;
			index++;
		}
		i+=2;
	}
}

int main() {
	// your code goes here
	sieve();
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",arr[n-1]);
	}
	return 0;
}
