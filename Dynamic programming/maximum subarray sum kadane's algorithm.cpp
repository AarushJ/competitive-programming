#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0 ; i<n ; i++)	cin >> arr[i];
	int globalMax = 0;
	int maxTillNow = 0;
	int sum = 0;
	
	for(int i=0 ; i<n ; i++){
		sum+=arr[i];
		if(sum < 0) sum = 0;
		if(sum > maxTillNow)
			maxTillNow = sum;                       						 
	}	
	bool flag = false;
	for(int i=0 ; i<n ; i++){
		if(arr[i] > 0){
			flag = true;
			break;
		} 
	}
	cout << ( (flag)?(max_so_far) : (*max_element(arr.begin(),arr.end()+1))) << "\n";
	return 0;
}
