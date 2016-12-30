#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

long int minimum(vector<long int> a,int size){
    long int min=INT_MAX;
    for(int i=0 ; i<size ; i++){
        if(a[i]<min) min=a[i];
    }
   
    return min;
}

int indexOfMinimum(vector<long int> a,int size){
    long int min=0;
    int indexOfMin=0;
    for(int i=0 ; i<size ; i++){
        if(a[i]>min){
            min=a[i];
            indexOfMin=i;
        }        
    }
    return indexOfMin;
}

int main() 
{
    int n;
    long k; 
    cin >> n >> k;
    vector<long int> prices(n);
    for(int i=0 ; i<n ; i++){
        cin >> prices[i];
    }
    
    int count=0;
    
    while(k>=minimum(prices,prices.size())){
        k=k-minimum(prices,prices.size());
        cout << k <<"    yo" << endl;
        count++;
        int a=indexOfMinimum(prices,prices.size());
        prices.erase(prices.begin()+a,prices.begin()+a);
    }
    
    cout << count << endl;
    
    return 0;
}

