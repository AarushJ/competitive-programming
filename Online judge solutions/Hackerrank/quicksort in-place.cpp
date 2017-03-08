#include<iostream>
using namespace std;

void swap2numbers(int *a,int*b ){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int firstIndex,int lastIndex,int sizeOfFullArray){
    int pivot=arr[lastIndex];
    int i=firstIndex-1;
    for(int j=firstIndex ; j<lastIndex ; j++){
        if(arr[j]<=pivot){
            i++;
            swap2numbers(&arr[i],&arr[j]);
        }
    }
    swap2numbers(&arr[i+1],&arr[lastIndex]);
    for(int j=0 ; j<sizeOfFullArray ; j++) {
		cout << arr[j] << " ";
	}
        cout << endl;
    return i+1;
}

void quickSort(int arr[],int firstIndex,int lastIndex,int sizeOfFullArray){
    if(firstIndex<lastIndex){
        int pivotIndex=partition(arr,firstIndex,lastIndex,sizeOfFullArray);
        quickSort(arr,firstIndex,pivotIndex-1,sizeOfFullArray);
        quickSort(arr,pivotIndex+1,lastIndex,sizeOfFullArray);
    }
}

int main(){
    int n;
    cin >> n;
    int num[n];
    for(int i=0 ; i<n ; i++) cin >> num[i];
    quickSort(num,0,n-1,n);
    return 0;
}
