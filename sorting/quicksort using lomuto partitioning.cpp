#include<iostream>
using namespace std;

#define loop(i,a,b) for(int i = int(a); i<int(b) ; i++)
#define rloop(i,a,b) for(int i = int(a); i>int(b) ; i--) // reverse iterating loop

void swap2numbers(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
} 

int partition(int arr[],int low,int high){
	int pivot = arr[low];
	int i = high+1;
	rloop(j,high,low){
		if( arr[j] >= pivot ){
			i--;
			swap2numbers(&arr[i],&arr[j]);
		}
	}
	swap2numbers(&arr[i-1],&arr[low]);
	return i-1;
}

void quickSort(int arr[],int low,int high){
	if( low < high ){
		int pivotIndex = partition(arr,low,high);
		quickSort(arr,low,pivotIndex-1);
		quickSort(arr,pivotIndex+1,high);
		}
	}
	
int main(){
	int n;
	cin >> n;
	int num[n];
	loop(i,0,n)		cin >> num[i];
	
	quickSort(num,0,n-1);
	
	loop(i,0,n)		cout << num[i] << " ";
	
	return 0;
}
