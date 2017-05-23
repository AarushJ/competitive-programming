/*
	AARUSH JUNEJA
	@vivace
	TOPICS : queues, simulation
*/

#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n;
	cin >> n;
	char c;
	queue<int> d,r;
	for(int i=0 ; i<n ; i++){
		cin >> c;
		if(c=='D')	d.push(i);
		else r.push(i);
	}
	while(!d.empty() && !r.empty()){
		if(d.front() < r.front()){
			r.pop();
			d.push(d.front()+n);
			d.pop();
		}else{
			d.pop();
			r.push(r.front()+n);
			r.pop();
		}
	}
	if(d.empty()) cout << 'R';
	else cout << 'D';
	return 0;
}
