#include<bits/stdc++.h>
using namespace std;

#define SIZE 26

typedef long long ll;

struct node{
	node *parent;
	node *child[SIZE];
	ll words;
	ll prefixes;
};

node* newNode(){
	node *a = new node;
	a->words = a->prefixes = 0;
	for(ll i=0 ; i<SIZE ; i++)	a->child[i] = NULL;
	return a;
}

void insert( node *a, string &s){
	node *ptr = a;
	ll sz = s.size();
	for(ll i=0 ; i<sz ; i++){
		ptr->prefixes++;
		ll idx = s[i]-'a';
		if(ptr->child[idx] == NULL){
			ptr->child[idx] = newNode();
			ptr->child[idx]->parent = ptr; // assigning parent
		}
		ptr = ptr->child[idx];
	}
	ptr->words++;
}

ll search( node *a, string &s){
	node *ptr = a;
	ll sz = s.size();
	for(ll i=0 ; i<sz ; i++){
		ll idx = s[i]-'a';
		if( ptr->child[idx] == NULL)	
			return 0;
		ptr = ptr->child[idx];	
	}
	if(ptr != NULL && ptr->words)	return ptr->words;
	return 0;
}

int main(){
	ll n,q;
	cin >> n;
	node *root = newNode();
	
	string s[n];
	for(ll i=0 ; i<n ; i++){
		cin >> s[i];
		insert( root, s[i]);
	}	
	
	cin >> q;
	
	while(q--){
		string ss;
		cin >> ss;
		
		ll res = search( root, ss);
		
		if(res){
			cout << ss << " is present " << res << " times\n";
		}else{
			cout << ss << " is not present\n";
		}
			
		
	}
		
	return 0;
}
