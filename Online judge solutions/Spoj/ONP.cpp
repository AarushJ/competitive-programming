#include <iostream>
#include<stack>
#include<string>
using namespace std;

int precedance(char a){
	if(a=='+' || a=='-') return 0;
	else if(a=='*' || a=='/' ) return 1;
	else if(a=='^') return 2;
	else return -1 ; // for left parenthesis in stack
}

bool isOperator(char a){
	if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^') return true;
	else return false;
}


int main() {
	stack<char> p;
	int t;
	cin >> t;
	string s;
	for(int i=0 ; i<t ; i++){
		cin >> s;
		p.push('(');
		s.push_back(')');
		string q;
		for(int j=0 ; !p.empty() ; j++){
			if( !isOperator(s[j]) && s[j]!='(' && s[j]!=')') q.push_back(s[j]);
			else if( s[j]=='(' ) p.push(s[j]);
			else if( s[j]==')' ){
				while(p.top()!='('){
					q.push_back( p.top() );
					p.pop();
				}
				p.pop();
			}
			else{
				while(precedance(p.top()) >= precedance(s[j])){
					q.push_back(p.top());
					p.pop();
				}
				p.push(s[j]);
			}
		}
		cout << q <<"\n";
	}
	return 0;
}
