#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		cout << "\n";
		int ng,nm;
		cin >> ng >> nm ;
		int max_ng=0,max_nm=0 ;
		int ng_strength,nm_strength ;
		for(int j=0 ; j<ng ; j++){
			cin >> ng_strength ;
			if(ng_strength > max_ng) max_ng = ng_strength ;
		}
		for(int j=0 ; j<nm ; j++){
			cin >> nm_strength ;
			if(nm_strength > max_nm) max_nm = nm_strength ;
		}
		if(max_ng>=max_nm) cout << "Godzilla\n";
		else cout << "MechaGodzilla\n";
	}
	return 0;
}
