#include<iostream>
#include<climits>
using namespace std;

long long inversions=0;

void merge(int arr[],int low,int mid,int high){
	int n1=mid-low+1;
	int n2=high-mid;
	int left[n1+1],right[n2+1];
	for(int i=0 ; i<n1 ; i++) left[i]=arr[low+i];
	for(int i=0 ; i<n2 ; i++) right[i]=arr[mid+1+i];
	left[n1]=INT_MAX;
	right[n2]=INT_MAX;
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

void mergeSort(int arr[],int low,int high){
	if( low<high ){
		int mid = (low+high) / 2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

int main(){
	int t ;
	cin >> t;
	for(int j=0 ; j<t ; j++){
		int n;
		cin >> n;
		int num[n];
		for(int i=0 ; i<n ; i++)	cin >> num[i];
		mergeSort(num,0,n-1);
		cout << inversions <<"\n" ;	
		inversions=0;
	}
	return 0;
}
