#include<iostream>
#include<vector>

using namespace std;

void partition(vector<int> &arr){
      int size=arr.size();
      
      if(size<2){
          return ;
      }
      
      vector<int> left,equal,right;
      int pivot=arr[0];
      for(int i=0 ; i<size ; i++){
            if(arr[i]<pivot) left.push_back(arr[i]);
            else if(arr[i]>pivot) right.push_back(arr[i]);
            else equal.push_back(arr[i]);
      }
      partition(left);
      partition(right);
      
      int leftSize=left.size(),rightSize=right.size(),equalSize=equal.size();
       
      for(int i=0 ; i<leftSize ; i++) cout << left[i] << " ";
      for(int i=0 ; i<equalSize ; i++) cout << equal[i] << " ";
      for(int i=0 ; i<rightSize ; i++) cout << right[i] << " ";
    
      int i=0;
    
      for(int j=0 ; j<leftSize ; j++) arr[i++]=left[j];
      for(int j=0 ; j<equalSize ; j++) arr[i++]=equal[j];
      for(int j=0 ; j<rightSize ; j++) arr[i++]=right[j]; 
      
      cout << endl;
}
int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    partition(arr);

    return 0;
}

