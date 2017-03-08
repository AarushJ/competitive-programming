#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int qswaps=0;

int insertionSortShifts(int arr[],int arrSize){
    int counter=0;
    for(int j=1;j<=(arrSize-1);j++){
        int key=arr[j];
        int i=j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i--;
            counter++;
        }
        arr[i+1]=key;
    }
    return counter;
}

void swap2numbers(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low ; j<high ; j++){
		if(arr[j]<=pivot){
			i++;
			swap2numbers(&arr[i],&arr[j]);
		    qswaps++;  
        }
	}
	swap2numbers(&arr[i+1],&arr[high]);
    qswaps++;
	return i+1;
}

void quickSort(int arr[],int low,int high){
	if(low<high){
		int pivotIndex=partition(arr,low,high);
		quickSort(arr,low,pivotIndex-1);
		quickSort(arr,pivotIndex+1,high);
	}
}


int main() {
    int n;
    cin >> n;
    int inum[n];
    int qnum[n];
    for(int i=0 ; i<n ; i++){
         cin >> inum[i];
        qnum[i]=inum[i];
    }
    int ishifts=insertionSortShifts(inum,n);
    quickSort(qnum,0,n-1);
    cout << ishifts-qswaps;
    return 0;
}
