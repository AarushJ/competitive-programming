#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		int n;
		cin >> n;
		int men[n],women[n];
		for(int j=0 ; j<n ; j++) cin >> men[j];
		for(int j=0 ; j<n ; j++) cin >> women[j];
		sort(men,men+n);
		sort(women,women+n);
		int sum=0;
		for(int j=0 ; j<n ; j++){
			sum+=(men[j]*women[j]);
		}
		cout << sum << endl;
	}
	return 0;
}
