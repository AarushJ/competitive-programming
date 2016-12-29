#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout << ((n%2)?("No"):("Yes"))<< "\n";
    }
    return 0;
}

