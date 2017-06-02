#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 

int main(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	priority_queue<ll> pq_max; 	// max heap
	priority_queue<ll, vector<ll>, greater<ll> > pq_min;	// min heap
	lp(i,n){
		cin >> v[i];
		pq_min.push(v[i]);
		pq_max.push(v[i]);
	}
	lp(i,n){
		cout << v[i] << " ";
	}
	cout << "\n\n";
	cout << "max heap : \n";
	while(!pq_max.empty()){
		cout << pq_max.top() << "\n";
		pq_max.pop();
	}
	cout << "\n";
	cout << "min heap : \n";
	while(!pq_min.empty()){
		cout << pq_min.top() << "\n";
		pq_min.pop();
	}
	
	// NOTE => If A and B are two priority queues of same data type, then A.swap(B) as well B.swap(A) 
	// 		   will swap the contents of A and B in constant time (Because C++ pointers rock)
	
	return 0;
}
