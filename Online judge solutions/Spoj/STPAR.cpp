#include <iostream>
#include<stack>
using namespace std;

int main() {
	// your code goes here
	while(1){
		int n;
		cin >> n;
		if(!n) break;
		else{
			stack<int> s;
            s.push(0);
			int arr[n];
			for(int i=0; i<n ; i++){
				cin >> arr[i];
			}
			bool flag = true;
			int need = 1;
            int i=0;
			while(need<=n){
				if(arr[i]==need){need++ ; 
                    i++ ;
                }
				else if(s.top()==need){
					need++ ;
					s.pop() ;
				}
				else if(s.top()<arr[i] && s.top()!=0){
					flag = false ;
					break;
				}
				else{
					s.push(arr[i]);
                    i++;
				}
            
			}
			if(flag) cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}
