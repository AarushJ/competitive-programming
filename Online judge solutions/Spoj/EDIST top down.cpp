#include<bits/stdc++.h>
using namespace std;

string s1,s2;

int edit(vector<vector<int> > &v,int a,int b){
	if( a == 0 || b == 0 )	return v[a][b]; 
	if(v[a][b] != -1) return v[a][b];
	if(s1[a-1]==s2[b-1]) v[a][b] = edit(v,a-1,b-1);
	else v[a][b] = min(min(edit(v,a-1,b) +1,edit(v,a,b-1)+1),edit(v,a-1,b-1)+1);
	return v[a][b];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> s1 >> s2;
		int a = s1.size(), b = s2.size();
		if(a > b){
			string temp = s2;
			s2 = s1;
			s1 = temp;
			a = s1.length() ; 
			b = s2.length() ;
		}
		vector<vector<int> > v(a+1,vector<int> (b+1,-1));
		for(int i=0 ; i<=a ; i++)	v[i][0] = i;
		for(int i=0 ; i<=b ; i++)	v[0][i] = i;
		cout << edit(v,a,b) << "\n";
	}
}
