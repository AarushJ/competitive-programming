#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long int n;
        cin >> n;
        int permanentN=n;
        int count=0;
        while(n!=0){
            if(permanentN%((n%10)?n%10:permanentN+1)==0){
                count++;
            }
            n/=10;
        }
        cout << count <<endl;
    }
    
    
    return 0;
}

