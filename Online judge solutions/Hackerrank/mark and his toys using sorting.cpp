#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	long k;
	cin >> n >> k;
	vector<int> price(n);
	
	for(int i=0 ; i<n ; i++){
		cin >> price[i];
	}
	sort(price.begin(),price.end());
	int i=0,count=0;
	
	while(k>=price[i]){
		k=k-price[i];
		count++;
		i++;
	}
	cout << count;
	
	return 0;
}
