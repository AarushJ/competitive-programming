#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n ;
    int num[n];
    for(int i=0 ; i<n ; i++) cin >> num[i];
    int count[100]={0};
    for(int i=0 ; i<n ; i++){
        count[num[i]]++;
    }
    for(int i=0 ; i<100 ; i++){
    	for(int j=0 ; j<count[i] ; j++){
    		cout << i << " ";
		}
    	
    }
    return 0;
}

