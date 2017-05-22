#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll l = 1,r = 1000,t = 1000,b = 0;
	ll a;
	ll mid = 1000,prev = -5,curr = 1000;
	string s;
	while(r>l){
		cout << "? " << mid << " " << 0 << "\n";
		fflush(stdout);
		cin >> s;
		if(s=="YES"){
			l = mid;
		}else{
			r = mid-1; 
		}
		mid = (l+r+1)/2;
 	}
	
	ll area = pow((l)*2,2);
	
	ll height = 2*l;  
	l = 1 , r = 1000;
	cout << "? " << r << " " << height << "\n";
	fflush(stdout);
	cin >> s;
	int base;
	if(s=="YES"){
		base = 2000;		
	}else{
		r = 1000;
		mid = 1000;
		while(r>l){
	
			cout << "? " << mid << " " << height << "\n";
			fflush(stdout);
			cin >> s;
			if(s=="YES"){
				l = mid;
			}else{
				r = mid-1; 
			}
			mid = (l+r+1)/2;
 		}
 		base = 2*l;
	}
	
	cout << "? " << 0 << " " << 1000 << "\n";
	fflush(stdout);
	cin >> s;
	int alt;
	if(s=="YES"){
		alt = 1000-height;
	}else{
		r = 1000;
		l = 1;
		mid = 1000;
		while(r>l){
	
		cout << "? " << 0 << " " << mid << "\n";
		fflush(stdout);
		cin >> s;
		if(s=="YES"){
			l = mid;
		}else{
			r = mid-1; 
		}
		mid = (l+r+1)/2;
 	}
 		alt = l-height;
	}
	
	area += (base*alt)/2;
	cout << "! " <<  area << "\n";
	return 0;
}
