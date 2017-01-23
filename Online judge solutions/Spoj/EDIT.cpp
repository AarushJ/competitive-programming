#include <iostream>
#include <cmath>
using namespace std;

int main() {
	char s[1001];
	while(scanf("%s",s)!=EOF){ 
		int i=0;
		int ans_low_case_start = 0,ans_upp_case_start = 0;
		while(s[i]!='\0'){ // low is first char
			if(i%2){
				if(!(s[i]>='A' && s[i]<='Z'))	ans_low_case_start++; 	
			}else{
				if(!(s[i]>='a' && s[i]<='z'))	ans_low_case_start++;
			}
			++i;
		}
		i=0;
		while(s[i]!='\0'){ // upp is first char
			if(i%2){
				if(!(s[i]>='a' && s[i]<='z'))	ans_upp_case_start++; 	
			}else{
				if(!(s[i]>='A' && s[i]<='Z'))	ans_upp_case_start++;
			}
			++i;
		}
		printf("%d\n",min(ans_low_case_start,ans_upp_case_start));
	}
	return 0;
}
