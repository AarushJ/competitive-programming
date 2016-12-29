#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int p,q;
    cin >>p >>q;
    int count=0;
    for(long long int i=p ; i<=q ; i++){    	
        long int temp=i*i;
        long int j=i*i;
        int digits=0;
        long long int l=0,r=0;
        while(temp!=0){
            temp/=10;
            digits++;
        }
        int leftHalf=digits/2;
        int rightHalf=digits-leftHalf;
        int leftDigit[leftHalf],rightDigit[rightHalf];
        for(int k=0 ; k<rightHalf ; k++,j/=10){
            rightDigit[k]=j%10;
        }
        for(int k=rightHalf-1 ; k>=0 ; k--){
        	r=10*r+rightDigit[k];
		}
        for(int k=0 ; k<leftHalf ; k++,j/=10){
            leftDigit[k]=j%10;
        }
        for(int k=leftHalf-1 ; k>=0 ; k--){
        	l=10*l+leftDigit[k];
		}
        
        if(l+r==i){
        	count++;
            cout << i << " ";
        }
		
    }
    if(!count){
			cout << "INVALID RANGE" ; 
		}     
    return 0;
}

