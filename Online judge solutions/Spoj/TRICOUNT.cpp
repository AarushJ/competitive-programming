 #include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		long long n;
		cin >> n;
		long long ans=(n*(n+1)*(n+2))/6; 
		if(n%2==0){
			n=n/2;
			ans=ans+((n*(n+1)*(4*n-1))/6);
		}
		else{
			n=n/2;
			ans=ans+((n*(n+1)*(4*n+5))/6);
		}
		cout << ans << endl ;
		
	}
	return 0;
}
