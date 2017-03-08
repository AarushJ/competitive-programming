#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num[n];
    for(int i=0 ; i<n ; i++) cin >> num[i];
    int pivot=num[0];
    vector<int> left,right,equal;
    for(int i=0 ; i<n ; i++){
        if(num[i]>pivot) right.push_back(num[i]);
        else if(num[i]<pivot) left.push_back(num[i]);
        else equal.push_back(num[i]);
    }
    int left_size=left.size(),equal_size=equal.size(),right_size=right.size();
    for(int i=0 ; i<left_size ; i++) cout << left[i] << " ";
    for(int i=0 ; i<equal_size ; i++) cout << equal
        [i] << " ";
    for(int i=0 ; i<right_size ; i++) cout << right[i] << " ";
    return 0;
}
