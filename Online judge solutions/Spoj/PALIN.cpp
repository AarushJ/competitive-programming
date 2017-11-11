#include <iostream>
using namespace std;

bool all9(string &s){
	int len = s.size();
	for(int i=0 ; i<len ; ++i)
		if(s[i]!='9')	return false;
	return true;
}

bool isPalin(string &s){
	int len = s.size();
	for(int i=0 ; i<len/2 ; i++)
		if(s[i]!=s[len-1-i])	return false;
	return true;
}

bool allZero( string &s){
	int len = s.size();
	for(int i = 0 ; i < len ; i++){
		if( s[i] != '0' )	return false;
	}
	return true;
}

void case9(string &s,int &lo,int &hi){
	if(s[lo]=='9'){
		while(s[lo]=='9'){
			s[lo] = '0';
			s[hi] = s[lo];
			lo-- , hi++;
		}
	}
	s[lo]++;
	s[hi] = s[lo];
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int t,len;
	cin >> t;
	string s;
	while(t--){
		cin >> s;
		len = s.size();
		if( allZero(s) ) {
			cout << 1 << "\n";
			continue;
		}
		if( len == 1 ){
			if( s[0]<='8')
				cout << s[0]+1-'0';
			else 
				cout << 11;
		}else if( all9(s) ){
			cout << 1 ;
			for(int i=1 ; i<len ; ++i)
				cout << 0;
			cout << 1;
		}else if( isPalin(s) ){
			int lo,hi;
			if(len%2)
				lo = len/2,hi = len/2;
			else
				lo = len/2-1,hi = len/2;
			case9(s,lo,hi);
			cout << s ;
		}else{
			int lo = -1,hi;
			for(int i=len/2-1 ; i>=0 ; i--){
				if(s[i] > s[len-1-i]){
					s[len-1-i] = s[i];
					lo = i-1;
					break; 	
				}
				else if(s[i] < s[len-1-i]){
					if(len%2)
						lo = len/2,hi = len/2;
					else
						lo = len/2-1,hi = len/2;			
					case9(s,lo,hi);
					break;		
				}
			}
			
			for(int i=0 ; i<=lo ; ++i)
				s[len-1-i] = s[i];	
			
			cout << s ;
		}	
		cout << "\n";
	}
	return 0;
}
