#include<bits/stdc++.h>
using namespace std;

#define ALPHABETSIZE 26

bool flag = false;	// to check if any answer exists or not

struct Trie{
	struct node{
		char data;
		bool word;
		node *child[ALPHABETSIZE];
	};
	
	public:
		node *root;
		Trie();	// constructor
		void insert(string &str);
		void init( node *ptr);
		void query(string &prefix);
		void recur(node *n,string &s);
};

Trie::Trie(){
	root = new node();
	init(root);
}

void Trie::init(node *ptr){
	ptr->word = false;
	for(int i = 0 ; i<26 ; i++)
		ptr->child[i] = NULL;
}

void Trie::insert(string &str){
	node *ptr = root; 
	int sz = str.size();
	for(int i = 0 ; i<sz ; i++){
		int idx = str[i]-'a';
		if( ptr->child[idx] == NULL ){
			ptr->child[idx] = new node;	
			init(ptr->child[idx]);
			ptr->child[idx]->data = str[i];
		}
		ptr = ptr->child[idx];
	}
	
	ptr->word = true;

}



void Trie::query(string &prefix){
	node *ptr = root;
	int sz = prefix.size();
	for(int i = 0 ; i<sz ; i++){
		int idx = prefix[i]-'a';
		if(ptr->child[idx] == NULL)
			return;
		ptr = ptr->child[idx];
	}

	recur(ptr,prefix);
}

void Trie::recur(node *n, string &prefix){
	node *ptr = n;
	for(int i = 0; i<26 ; i++){
		if( ptr->child[i] != NULL ){
			string curr = prefix;
			curr += ptr->child[i]->data;
			if( ptr->child[i]->word ){
				cout << curr << "\n";
				flag = true;
			}
				
			recur( ptr->child[i], curr);
		}
	}
}


int main(){
	int n,t;
	cin >> n;
	Trie T;
	for(int i = 0 ; i<n ; i++){
		string str;
		cin >> str;
		T.insert(str);
	}
	
	cin >> t;
	for(int i = 1 ; i <= t ; i++){
		string prefix;
		cin >> prefix;
		
		cout << "Case #" << i << ":\n";
		T.query(prefix);
	
		if( !flag )
			cout << "No match.\n";
		else
		 flag = false;
	}
	
	
	return 0;
}
