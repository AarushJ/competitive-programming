#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	++t;
	getchar();
	
	while(--t){
		getchar();
		int num1 = 0,num2 = 0 ,num3 = 0;
		bool m_gone = false;
		char ch;
		
		while(1){
			ch = getchar();
			if(ch!='m' && ch!=' '){
				num1 = num1*10+ch-'0';
			}else{
				break;
			}
		}
		if(ch == 'm'){
			while(getchar()!='+'){
				
			}
			getchar();
			cin >> num2;
			getchar();getchar();getchar();
			cin >> num3;
			cout << num3-num2 << " + " << num2 << " = " << num3 << "\n";
			getchar();
		}else{ // first number complete
			getchar();getchar();
			while(1){
				ch = getchar();
				if(ch!='m' && ch!=' '){
					num2 = num2*10+ch-'0';
				}else{
					break;
				}	
			}
			if(ch=='m'){
				while(getchar()!='='){
					
				}
				getchar();
				cin >> num3;
				cout << num1 << " + " << num3-num1 << " = " << num3 << "\n";
				getchar();
			}else{ // 2nd number complete
				cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
				while(getchar()!='\n'){
					
				}
			}
		}
	}
	return 0;
}
