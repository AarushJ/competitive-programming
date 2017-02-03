#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	// cin.tie(0);
	int t,n;	
	cin >> t;
	map<string,int> m;
	while(t--){
		cin >> n;
		
		string s;
		
		for(int i=0 ; i<n ; i++){
			string str = "";
			cin >> s;
			str += s;
			for(int i=0 ; i<5 ; i++){
				cin >> s;
				str += " ";
				str += s;
			}
			if(m.find(str)!=m.end()){
				m[str] += 1;
			}else{
				m[str] = 1;
			}
		}
		map<string,int>::iterator it;
		for(it = m.begin() ; it!=m.end() ; it++){
			cout << it->first << " " << it->second << "\n";
		}
		m.clear();
	}
	return 0;
}
