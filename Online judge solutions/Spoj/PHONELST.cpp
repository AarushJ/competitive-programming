#include<bits/stdc++.h>
using namespace std;

#define SIZE 10

typedef long long ll;

// trie node
struct node{
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
		ll idx = s[i]-'0';
		if(ptr->child[idx] == NULL){
			ptr->child[idx] = newNode();
		}
		ptr = ptr->child[idx];
	}
	ptr->words++;
}

ll countPrefixes( node *a, string &s){
	node *ptr = a;
	ll sz = s.size();
	for(ll i=0 ; i<sz ; i++){
		ll idx = s[i]-'0';
		if( ptr->child[idx] == NULL)	
			return 0;
		ptr = ptr->child[idx];	
	}
	if(ptr != NULL && ptr->prefixes)	return ptr->prefixes;
	return 0;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n,q;
		cin >> n;
		node *root = newNode();
	
		string s[n];
		for(ll i=0 ; i<n ; i++){
			cin >> s[i];
			insert( root, s[i]);
		}
		
		ll res = 0;
		for(ll i=0 ; i<n ; i++){
			res = countPrefixes( root, s[i]);
			if(res)	break;
		}
	
		if(res) cout << "NO\n";
		else cout << "YES\n";	
		delete root;
	}
	
	
	return 0;
}
