#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>                         
#include <algorithm>
#include<string>
using namespace std;
                                                //01 hh //34 mm //67ss //89 AM/PM
int main(){
    char s[10];
    for(int i=0 ; i<10 ; i++){
    	cin >> s[i];
	}
    if(s[0]==1 && s[1]==2 && s[3]==0 && s[4]==0 && s[6]==0 && s[7]==0){
        if(s[8]=='A'){
            s[0]=0;
            s[1]=0;
            for(int i=0 ; i<=7 ; i++ ){
                cout << s[i];
            }
            
        }else{
            for(int i=0 ; i<=7 ; i++ ){
                cout << s[i];
            }
        }
    }else if(s[0]=1 && s[1]==2){
        if(s[8]=='A'){
            s[0]=0;
            s[1]=0;
            for(int i=0 ; i<=7 ; i++ ){
                cout << s[i];
            }
        }else{
            for(int i=0 ; i<=7 ; i++ ){
                cout << s[i];
            }
        }
    }else{
        if(s[8]=='P'){
            s[0]=1;
            s[1]=(s[1]+12)%10;
            for(int i=0 ; i<=7 ; i++ ){
                cout << s[i];
            }
        }else{
            for(int i=0 ; i<=7 ; i++ ){
                cout << s[i];
            }
        }
    }
    
    return 0;
}

