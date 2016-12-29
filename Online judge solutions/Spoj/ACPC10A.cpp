#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	while(1){
		cin >> a >> b >> c;
		if(a or b or c){
			
			if(b==(a+c)/2.0) cout << "AP " << 2*c-b << endl;
			
			else if(b*b==a*c) cout << "GP " << c*(float(c))/b << endl ;
		
		}else{
			break;
		}
	}	

	return 0;
}
