#include<bits/stdc++.h>
using namespace std;

int sum(int a[],int lo,int hi){
	int res = 0;
	for(int i=lo ; i<=hi ; i++){
		res+=a[i];
	}
	return res;
}

void merge(int arr[],int lo,int mid,int hi){
	int ll = mid-lo+1 , rr = hi-mid;
	int left[mid-lo+2],right[hi-mid+1];
	for(int i=0 ; i<ll ; i++)	left[i] = arr[lo+i];
	for(int i=0 ; i<rr ; i++)	right[i] = arr[i+mid+1];
	left[mid-lo+1] = INT_MAX;
	right[hi-mid] = INT_MAX;
	int k=lo,i=0,j=0;
	for(int k=lo ; k<=hi ; k++){
		if(left[i] < right[j]){
			arr[k] = left[i];
			i++;
		}else{
			arr[k] = right[j];
			j++;
		}
	}
}

void mergeSort(int arr[],int lo,int hi){
	if(lo < hi){
		int mid = (lo+hi)/2;
		mergeSort(arr,lo,mid);
		mergeSort(arr,mid+1,hi);
		merge(arr,lo,mid,hi);
	}
}

int purchase_flw(int n,int k,int price[],int count[],int per[],int lo,int hi){
	mergeSort(price,lo,hi);
	if(n <= k)	return sum(price,lo,hi);
	int res = 0;
	int cc = k , i=hi;
	for(int i=hi ; cc ; cc--,i--){
		res += price[i];
	}

	for(int j=0 ; j<k ; j++){
		count[j] = 1;
	}
	int per_index = 0;
	i = hi-k;

	while(i>=0){
		if(per_index >= k)	per_index = 0;
		res += (count[per_index]+1)*price[i];
		count[per_index]++;
		per_index++;
		i--;
	}
	return res;
}

int main(){
	int n,k;
	cin >> n >> k;
	int per[k],price[n],count[k];
	for(int i=0 ; i<n ; i++)	cin >> price[i];
	for(int i=0 ; i<k ; i++)	count[i] = 0,per[i] = 0;
	cout << purchase_flw(n,k,price,count,per,0,n-1);	
	return 0;
}
