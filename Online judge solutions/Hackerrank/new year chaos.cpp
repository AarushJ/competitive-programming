#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int p=0 ; p<t ; p++){
		int n,swaps,ans=0;
		bool flag=true;
		cin >> n;
		int num[n];
		for(int i=0 ; i<n ; i++) cin >> num[i];
		// insertion sort	
		for(int i=n-2 ; i>=0 ; i--){
			int key=num[i];   
			int j=i+1;
			swaps=0;
			while(j<=n-1 && num[j]<key ){
				num[j-1]=num[j];
				j++;
				if(++swaps > 2){
					flag=false;
					break;
				}
			}
			if(flag){
				num[j-1]=key;
				ans+=swaps;
			} 
			else break;
		}
		if(flag) cout << ans << "\n";
		else cout << "Too chaotic\n"; 
	}
	return 0;
}
