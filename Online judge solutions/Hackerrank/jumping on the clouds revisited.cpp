#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    int energy=100;
    cin >> n >> k;
    int cloud[n];
    for(int i=0 ; i<n ; i++){
        cloud[i];
    }
    for(int i=k ; i<=n ; i+=k){
        (cloud[(i)%n])?energy=energy-3:energy--;
    }
    cout << energy;
    return 0;
}
