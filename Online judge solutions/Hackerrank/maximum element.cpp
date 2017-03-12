#include <cmath>
#include <cstdio>
#include <stack>
#include <set>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    stack<int> s1,s2;
    cin >> n;
    int MAX = INT_MIN;
    while(n--){
        int a;
        cin >> a;
        if(a == 1){
            int b;
            cin >> b;
            MAX = max(MAX,b);
            s1.push(b);
        }else if(a == 2){
                if(s1.top()!=MAX){
                    s1.pop();
                }else{
                    s1.pop();
                    MAX = INT_MIN;
                    while(!s1.empty()){
                        MAX = max(MAX,s1.top());
                        s2.push(s1.top());
                        s1.pop();
                    }
                    while(!s2.empty()){
                        s1.push(s2.top());
                        s2.pop();
                    }
                }           
        }
        else{
            cout << MAX << "\n";
        }
    }
    return 0;
}

