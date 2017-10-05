
const ll BITS = 32;
vector<ll> to_binary(ll num){
	vector<ll> v;
	while( num > 0 ){
		v.pb(num%2);
		num >>= 1;
	}
	while( v.size() != BITS )	v.pb(0);
	reverse(all(v));
	return v;
}

ll from_binary(vector<ll> &v){
	ll num = 0;
	reverse(all(v));
	lp(i, BITS){
		num = num + v[i]*(1 << i);
	}
	return num;
}

// 0-1 trie
struct node{
	ll cnt;
	node *c[2];
	node(){
		cnt = 0;
 		c[0] = c[1] = NULL;
	}
};
node *root = new node();

void insert(ll n){
	vector<ll> binary = to_binary(n);
	ll sz = binary.size();
	node *p = root;
	lp(i, sz){
		if( p -> c[binary[i]] == NULL ){
			p -> c[binary[i]] = new node();
		}
		p = p -> c[binary[i]];
	}
	(p -> cnt)++;
}

// pair of distinct indices with maximum xor in array
ll maxQuery(ll n){
	if( root -> c[0] == NULL && root -> c[1] == NULL )	return 0;	// querying empty tree
	vector<ll> num = to_binary(n);
	node *p = root;
	vector<ll> ans;
	lp(i, BITS){
		if( p -> c[1 - num[i]] ){
			ans.pb(1);
			p = p -> c[1 - num[i]];
		}else{
			ans.pb(0);
			p = p -> c[num[i]];
		}
	}
	ll res = from_binary(ans);
	return res;
}

// pair of distinct indices with minimum xor in array
ll minQuery(ll n){
	if( root -> c[0] == NULL && root -> c[1] == NULL )	return LLONG_MAX;	// querying empty tree
	vector<ll> num = to_binary(n);
	node *p = root;
	vector<ll> ans;
	lp(i, BITS){
		if( p -> c[num[i]] ){
			ans.pb(0);
			p = p -> c[num[i]];
		}else{
			ans.pb(1);
			p = p -> c[1 - num[i]];
		}
	}
	ll res = from_binary(ans);
	return res;	
}

// helper function to print a trie -> DONT CALL DIRECTLY. This is only to be called from => print() function written just below this function  
void printHelp(node *p, ll val, vector<ll> &v){
	if( p != root )	
		v.pb( val );
	if( p -> cnt > 0 ){
		ll cnt = p -> cnt;
		while(cnt--)	lpit(it, v)	cout << *it;
		cout << "\n";
	}
	if( p -> c[0] )	printHelp( p -> c[0], 0, v);
	if( p -> c[1] )	printHelp( p -> c[1], 1, v);
	if( !v.empty()) v.pop_back();
}

// to print all numbers present in the 0-1 trie, in binary
void print(){
	node *ptr = root;
	vector<ll> v;
	printHelp(ptr, -1, v);
}

