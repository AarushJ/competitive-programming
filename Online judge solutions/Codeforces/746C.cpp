#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double s,x1,x2,t1,t2,p,d;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    
    int igorTime = abs(x1-x2)*t2;
    int d1 = ((x2>x1)?(1):(-1));
    
    double igorSpeed = 1/t2,tramSpeed = 1/t1;
    
    if(igorSpeed > tramSpeed) cout << igorTime;
    else{
        int t;
        if(d1==-1){
            if(d1==d){
                if(p<x2){
                    t = (p+2*s-x2)*t1;
                }else if(p>=x2 && p<=x1){
                    t = (p+2*s-x2)*t1;
                }else{
                    t = (p-x2)*t1;//t = (s+x2-2*x1)*t1;
                }
            }else{
                if(p<x2){
                    t= (2*s-p-x2)*t1;
                }else if(p>=x2 && p<=x1){
                    t = (2*s-p-x2)*t1;
                }else{
                    t = (2*s-p-x2)*t1;
                }
            }
        }else{
            if(d1==d){
                if(p<x1){
                    t = (x2-p)*t1;
                }else if(p>=x1 && p<=x2){
                    t = (2*s+x2-p)*t1;
                }else{
                    t = (2*s+x2-p)*t1;
                }
            }else{
                if(p<x1){
                    t = (p+x2)*t1;
                }else if(p>=x1 && p<=x2){
                    t = (p+x2)*t1;
                }else{
                    t = (p+x2)*t1;
                }
            }
        }
        cout << min(igorTime,t);
    }
        return 0;
}
