#include <iostream>
#include <set>
using namespace std;

int main() {
	int n,a,m;
	cin >> n;
	int temp = n;
	set<int> s;
	while(n--){
		cin >> a >> m;
		s.insert(a);
		while(m--){
			cin >> a;
			s.insert(a);
		}
	}
	cout << s.size()-temp;
	return 0;
}
