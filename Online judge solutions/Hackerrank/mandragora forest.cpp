#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int health[n];
        long long int sum = 0;
        for(int i=0 ; i<n ; i++){
            cin >> health[i];
            sum += health[i];
        }
        long long max  ;
        long long int ans = sum;
        sort(health,health+n);
        for(int i=1 ; i<=n ; i++){
            sum -= health[i-1];
            max = (long long)sum*(i+1);
            if(max > ans) ans = max;
        }
        cout << ans << "\n";
    }
    return 0;
}

