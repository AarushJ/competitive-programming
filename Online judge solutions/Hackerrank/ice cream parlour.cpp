#include<vector>
#include<utility>
#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(vector<pair<int,int> >  &arr,int low,int high,int x){
	int mid;
	bool flag = false;
	while(low<=high){
		mid = low+(high-low)/2;
		if(arr[mid].first<x){
			low = mid+1;
		}else if(arr[mid].first>x){
			high = mid-1;
		}else{
			flag = true;
			break;
		}
	}
	if(flag) return arr[mid].second;
	else return -1;
}

int main() {
    int t;
    cin >> t;
    int m,n;
    while(t--){
        cin >> m >> n;
        vector<pair<int,int> > cost(n);
        for(int i=0 ; i<n ; i++){
            cin >> cost[i].first;
            cost[i].second = i+1;
        }
        sort(cost.begin(),cost.end());
        for(int i=0 ; i<n ; i++){
            if(cost[i].first<m){
                int a = binarySearch(cost,i+1,n-1,m-cost[i].first);             
                if(a!=-1){
                    cout << a << " " << cost[i].second << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}

