#include <iostream>
#include<cmath>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int g,b;
	while(1){
		cin >> g >> b;
		if(g == -1)	break;
		else{
			cout << ceil((double)max(g,b)/(min(g,b)+1)) << "\n";
		}
	}
	return 0;
}
