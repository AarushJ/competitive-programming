#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	while(1){
		int a,d;
		scanf("%d %d",&a,&d);
		if(a && d){
			int b;
			int min = 1000000,least = 1000000,secondLeast = 10000000,leastIndex;
			
			for(int i=0 ; i<a ; i++){
				scanf("%d",&b);
				if(min > b)	min = b;
			}
			
			int c[d];
			for(int i=0 ; i<d ; i++){
				scanf("%d",&c[i]);
				if(c[i] < least){
					least = c[i];
					leastIndex = i;
				}	
			}
			
			for(int i=0 ; i<d ; i++){
				if(c[i] < secondLeast && i!=leastIndex)	secondLeast = c[i];
			}
			
			if(min < secondLeast){
				printf("Y\n");
			}else{
				printf("N\n");
			}
		}else{
			break;
		}
	}
	return 0;
}
