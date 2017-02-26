#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	while(n--){string a;cin >> a;long long b;cin >> b;int l=a[a.length()-1]-'0';
		int arr2[4]={6,2,4,8},arr3[4]={1,3,9,7},arr4[2]={6,4},arr7[4]={1,7,9,3},arr8[4]={6,8,4,2},arr9[2]={1,9};
		if(b==0)cout << 1;else if(l==0)cout << 0;else if(l==1)cout << 1;
		else if(l==2){
			cout << arr2[b%4];
		}
		else if(l==3){
			cout << arr3[b%4];
		}else if(l==4){
			cout << arr4[b%2];
		}
		else if(l==5)cout << 5;
		else if(l==6)cout << 6;
		else if(l==7){
			cout << arr7[b%4];
		}
		else if(l==8){
			cout << arr8[b%4];
		}
		else if(l==9){
			cout << arr9[b%2];
		}
		cout << "\n";
	}
	return 0;
}
