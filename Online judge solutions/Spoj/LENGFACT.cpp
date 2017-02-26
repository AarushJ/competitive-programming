#include <iostream>
#include <cmath>
using namespace std;
#define E 2.71828182845904523536
int main() {
	int t;
	scanf("%d",&t);
	long long n;
	while(t--){
		scanf("%lld",&n);
		if(n<=1)	printf("1\n");
		else{
			long long ans = (long long) (n*log10(n/E) + log10(2*acos(-1)*n)/2);
			printf("%lld\n",ans+1);
		}
	}
	return 0;
}
