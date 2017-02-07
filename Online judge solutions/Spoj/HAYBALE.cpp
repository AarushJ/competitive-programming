#include <iostream>
#include <algorithm>
using namespace std;
#define loop(i,a,b) for(int i=(int)a ; i<(int)b ; ++i)
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,l,r;
	short k;
	cin >> n >> k;
	short arr[n+1] = {0};
	loop(i,0,k){
		cin >> l >> r ;
		++arr[l],--arr[r+1];
	}
	
	loop(i,1,n)
		arr[i] += arr[i-1];
	
	sort(arr,arr+n);
	cout << arr[n/2];
	return 0;
}
