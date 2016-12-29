#include <iostream>
using namespace std;

bool isPalin(string &s){
	int len = s.size()-1;
	for(int i=0 ; i<=len/2 ; i++){
		if(!(s[i]==s[len-i]))	return false;	
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	string s;
	while(t--){
		cin >> s;
		if(isPalin(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
