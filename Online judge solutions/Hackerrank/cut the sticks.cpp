#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int stick[n];
    for(int i=0 ; i<n ; i++){
        cin >> stick[i];
    }
    sort(stick,stick+n);
    int i=0,minLength;
    while(i<n-1){
    	while(stick[i]==0){
			i++;
		}
		cout <<n-i <<endl;
			minLength=stick[i];
		for(int j=i ; j<n ; j++ ){
			stick[j]-=minLength;
		}
	}    
    return 0;
}

