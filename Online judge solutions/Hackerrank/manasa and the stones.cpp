#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkPresence(vector<int> &vec,int p,int size){
    bool check=false;
    for(int i=0 ; i<size ; i++){
        if(vec[i]==p){
            check=true;
            break;
        }
    }
    return check;
}

int main() {
    int t;
    cin >> t;
    for(int i=0 ; i<t ; i++){
        int n,a,b;
        cin >> n >> a >> b;
        vector<int> differentNumber;
        int size=0;
        for(int j=0 ; j<=n-1 ; j++){
            int c=(n-1-j)*a+j*b;
            if(!checkPresence(differentNumber,c,size)){
                differentNumber.push_back(c);
                size++;
            }
        }
        sort(differentNumber.begin(),differentNumber.end());
        for(int j=0 ; j<size ; j++){
            cout << differentNumber[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

