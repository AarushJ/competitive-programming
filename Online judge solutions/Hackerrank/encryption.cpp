#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    int length=s.length();
    int row=floor(sqrt(length)),col=ceil(sqrt(length));
    if(row*col<length) row++;
    
    for(int i=0 ; i<col ; i++ ){
        for(int j=i ; j<length ; j+=col ){
            cout << s[j];
        }
        cout << " ";
    }
    return 0;
}

