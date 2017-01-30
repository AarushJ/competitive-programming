#include<bits/stdc++.h>
using namespace std;

int min_subarray_sum_kadane(vector<int> &v,int &globalLeft,int &globalRight){
	
	int lo = 0,hi = v.size();
	int currentLeft  = lo,currentRight = hi,currentSum = 0;
	int globalSum = INT_MAX;
	
	for(int i=lo ; i<hi ; i++){
		currentSum += v[i];
		if(currentSum < globalSum){
			globalSum = currentSum;	
			currentRight = i;
			globalLeft = currentLeft;
			globalRight = currentRight;
		}	
		if(currentSum > 0){
			currentSum = 0;
			currentLeft = currentRight = i+1;
		}
	}
	
	bool flag = false;
	for(int i=lo ; i<hi ; i++){ // check for all positive elements type of array
		if(v[i] < 0 ){
			flag = true;
			break;	
		}
	}
	if(!flag){
		globalSum = INT_MAX;
		for(int i=lo ; i<hi ; i++){
			if(globalSum >= v[i] ){
				globalSum = v[i];
				globalLeft = globalRight = i;
			}
		} 
	}
	return globalSum;
}

int main(){
	int n; // size of array/vector
	cin >> n;
	vector<int> v(n);
	for(int i=0 ; i<n ; i++)	cin >> v[i];
	
	int globalLeft,globalRight;
	
	cout << min_subarray_sum_kadane(v,globalLeft,globalRight);
	
	return 0;
}
