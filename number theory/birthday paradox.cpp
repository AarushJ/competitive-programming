#include<iostream>				// learnt from geeksforgeeks.org
#include<cmath>
using namespace std;

int main(){
	double p ; 		// p is required the probability that 2 people out of n people in a room have same birthday 
	cin >> p; 		// p <1 and p >=0 
	cout << ceil(sqrt(2*365*log(1/(1-p))));   // this is the smallest number of people 
	return 0;								  // needed in a room to make the probability >= p 	
}
