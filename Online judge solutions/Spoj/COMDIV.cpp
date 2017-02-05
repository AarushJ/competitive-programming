#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){if(!a) return b; return gcd(b%a,a); }
#define gc getchar
int ip(){
	int x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc() )	x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}

int main(){
	//ios::sync_with_stdio(false)
	int t,a,b,h,ans,i;
	t = ip();
	while(t--){
		a = ip() ; b = ip();
		h = gcd(a,b);
		ans = 0;
		for( i=1 ; i*i<=h ; i++){
			if(h%i==0){
				ans += 2;
			}
		}
		i--;
		if(i*i==h)	ans--;
		cout << ans << "\n";
	}
	return 0;
}
