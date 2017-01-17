#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,c,m,val;
    cin >> n >> c >> m;
    int maxx = m*c;
    bool flag = true;
    for(int i=0 ; i<n ; ++i){
        cin >> val;
        if(val > m*c ) {
            flag = false;
            break;
        }
    }
    cout << ((flag)?("Yes\n"):("No\n"))	;
    return 0;
}

