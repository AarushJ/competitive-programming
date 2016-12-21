#include<climits>
#include<iostream>
using namespace std;

#define loop(i,a,b) for(int i = int(a); i<int(b) ; i++)

void merge(int arr[],int low ,int mid ,int high){
	int n1 = mid-low+1;
	int n2 = high-mid;
	int left[n1+1],right[n2+1],i,j,k;
	
	loop(i,0,n1)	left[i] = arr[low+i];
	loop(j,0,n2)	right[j] = arr[mid+1+j];
	
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	i=0;
	j=0;
	
	loop(k,low,high+1){  			// runs till (high+1-1) ; see line 5 if u don't understand .
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
	}
}

void mergeSort(int arr[],int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort( arr,low,mid);
		mergeSort( arr,mid+1,high);
		merge(arr,low,mid,high);	
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int numbers[n];
	int i;
	loop(i,0,n)		scanf("%d",&numbers[i]);
	
	mergeSort(numbers,0,n-1);
	
	loop(i,0,n)		printf("%d ",numbers[i]);
	
	return 0;
} 
