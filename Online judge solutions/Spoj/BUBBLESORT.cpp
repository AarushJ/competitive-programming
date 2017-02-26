#include<iostream>
#include<climits>
#define MOD 10000007
using namespace std;

long long inversions=0;

void merge(long long arr[],long long low,long long mid,long long high){
	int n1=mid-low+1;
	long long n2=high-mid;
	long long left[n1+1],right[n2+1];
	for(int i=0 ; i<n1 ; i++) left[i]=arr[low+i];
	for(int i=0 ; i<n2 ; i++) right[i]=arr[mid+1+i];
	left[n1]=LLONG_MAX;
	right[n2]=LLONG_MAX;
	int i=0,j=0;
	for(int k=low ; k<=high ; k++){
		if(left[i] > right[j]){
			arr[k]=right[j];
			j++;
		}else{
			arr[k]=left[i];
			i++;
			inversions+=j;
		}
	}
}

void mergeSort(long long arr[],long long low,long long high){
	if( low<high ){
		long long mid = (low+high) / 2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

int main(){
	int t ;
	cin >> t;
	cout <<"\n";
	for(int j=1 ; j<=t ; j++){
		int n;
		cin >> n;
		long long num[n];
		for(int i=0 ; i<n ; i++)	cin >> num[i];
		mergeSort(num,0,n-1);
		cout << "Case " << j << ":" <<  inversions%MOD <<"\n" ;	
		inversions=0;
	}
	return 0;
}
