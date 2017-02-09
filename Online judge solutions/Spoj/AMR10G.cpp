#include<bits/stdc++.h>
using namespace std;

#define gc getchar

int ip(){
	int x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc() )	x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}

int main(){
	int n,k;
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		n = ip() , k = ip();
		vector<int> v(n);
		for(int i=0 ; i<n ; i++)	v[i] = ip();
		if( k == 1)	cout << 0 << "\n";
		else if(n==k)	cout << *max_element(v.begin(),v.end()) - *min_element(v.begin(),v.end()) << "\n";
		else{
			sort(v.begin(),v.end());
			int ans = 2000000000;
			for(int i=k-1 ; i<n ; i++){
				ans = min(ans,v[i]-v[i-(k-1)]);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
