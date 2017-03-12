#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0 ; i<t ; i++ ){
        int n ;
        cin >> n;
        int num[n];
        long long int sum[n]={0};
        int count=0;
        //array input and storing sum of first i elements in i-1 index(ith storage container) 
        cin >> num[0];
        sum[0]=num[0];
		for(int j=1 ; j<n ; j++){
            cin >> num[j] ;
            sum[j]=sum[j-1]+num[j] ;       
        }
        if(n==1){
        	count++;
		}else{
        	for(int j=0 ; j<n ; j++){        	
            	if(sum[j-1]==sum[n-1]-sum[j] ){
                	count++;
                	break;
            	}
        	}
    	}
        if(count){
            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
    }
    
    return 0;
}
