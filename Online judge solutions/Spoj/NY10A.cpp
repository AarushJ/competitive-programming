#include <iostream>
#include <vector>
using namespace std;

int count(vector<string> &v,string s){
	for(int i=0 ; i<8 ; i++){
		if(s == v[i])	return i;
	}
}

int main() {
	vector<string> v(8);
	v[0] = "TTT";
	v[1] = "TTH";
	v[2] = "THT";
	v[3] = "THH";
	v[4] = "HTT";
	v[5] = "HTH";
	v[6] = "HHT";
	v[7] = "HHH";
	int p;
	cin >> p;
	for(int i=1 ; i<=p ; i++){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans[8] = {0};
		string temp = "";
		for(int j=1 ; j<=38 ; j++){
			temp+=s[j-1];
			temp+=s[j];
			temp+=s[j+1];	
			ans[count(v,temp)]++;
			temp.clear();
		}
		cout << n << " ";
		for(int j=0 ; j<8 ; j++) cout << ans[j] << " ";
		cout << "\n"; 
	}
	return 0;
}
