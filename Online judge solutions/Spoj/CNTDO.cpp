#include<iostream>
#include<map>
#include<utility>
using namespace std;

int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		int a;
		map<int,int> m;
		for(int i=0 ; i<n ; i++){
			cin >> a;
			if(m.find(a)!=m.end()){
				m[a]++;
			}else{
				m[a] = 1;
			}
		}
		int ans = 0;
		for(auto &it : m){
			if(m.find(2*it.first)!=m.end())
				ans += it.second;
		}
		cout << ans << "\n";
	}
	return 0;
}
