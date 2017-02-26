#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=1 ; i<=t ; i++){
		int need,friends;
		cin >> need >> friends;

		vector<int> stamps(friends);
		for(int j=0 ; j<friends ; j++){
			cin >> stamps[j];
		}
		
		sort(stamps.begin(),stamps.end());

		int stamps_borrowed=0;
		int ans=0;
		bool flag=0;

		for(int j=friends-1 ; j>=0 ; j--){
			stamps_borrowed+=stamps[j];
			ans++;
			if(stamps_borrowed >= need ){
				flag=1;
				break;
			}
		}
		cout <<  "Scenario #" << i << ":" << endl ;
		if(flag){
			cout << ans ;
		}else{
			cout << "impossible" ;
		}
		
		cout << endl << endl;
	}
	return 0;
}
