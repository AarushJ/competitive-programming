#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=1 ; i<=t ; i++){
		long n;
		cin >> n;
		long start=1;
		char starter='x';
		if(n==1){
			cout << "TERM 1 IS 1/1" << endl;
			continue;
		}
		for(long j=2 ; 1 ; j++){
			long end=start + j;
			
			if(starter=='x') starter='y';
			else starter='x';
	
			if( n>start && n<=end ){
				long permanentN=n;
				n=n-start;
				long ans_x=0,ans_y=0;
				if(starter=='x'){
					ans_x=(j-n+1);
					ans_y=n;					
				}else{
					ans_x=n;
					ans_y=j-n+1;
				}
				
				cout << "TERM " << permanentN << " IS " << ans_x << "/" << ans_y << endl;
				break;
			
			}
	
			start=end;
		}
	}
	return 0;
}

