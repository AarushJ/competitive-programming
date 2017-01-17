#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		double n,k,m;
		long long ans = 0;
		cin >> n >> k >> m;
		if(n >= m) cout << 0;
		else{
			while(k*n > n && k*n <= m)
				++ans , n = k*n;
			cout << ans;
		}
		cout << "\n";
	}
	return 0;
}
