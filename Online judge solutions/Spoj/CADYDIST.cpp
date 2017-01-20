#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long long n;
	while(1){
		cin >> n;
		if(n==0) return 0;
		vector<long long> strength(n),price(n);
		for(int i=0 ; i<n ; i++) cin >> strength[i];
		for(int i=0 ; i<n ; i++) cin >> price[i];
		
		sort( strength.begin() , strength.end() ) ;
		sort( price.begin() , price.end() ) ;
		
		reverse( price.begin() , price.end() );
		
		long long ans=0;
		
		for(int i=0 ; i<n ; i++) ans+=( strength[i]*price[i] );			
		
		cout << ans << "\n" ;
		
	}
	return 0;
}
