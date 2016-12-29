#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int n,k;
    cin >> n >> k;
    long int luck=0;
    vector<long int> L;
    for(int i=0 ;i<n ; i++){
        int l,t;
        cin >>l >>t;
        if(t==0){
            luck+=l;
        }else{
            L.push_back(l);
        }
    }
    int size=L.size();
    sort(L.begin(),L.end());
    if(size>=k){
        for(int i=size-1 ; i>=abs(size-k) ; i--){
            luck+=L[i];
        }
    }
    else{
        for(int i=0 ; i<size ; i++){
          luck+=L[i];
        }  
    }
    for(int i=0 ; i<size-k ; i++){
        luck-=L[i];
    }
    cout << luck;
    return 0;
}

