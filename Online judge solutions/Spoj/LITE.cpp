#include<bits/stdc++.h>
using namespace std;

const int maxx = 100010;
int tree[4*maxx][2];
int lazy[4*maxx];

void prop(int pos, int lo, int hi){
	int l = 2*pos+1;
	if( lo != hi ){
		lazy[l] = 1 - lazy[l];
		lazy[l+1] = 1 - lazy[l+1];
	}
	swap(tree[pos][0], tree[pos][1]);
	lazy[pos] = 0;
}

void merge(int pos){
	int l = 2*pos+1;
	tree[pos][0] = tree[l][0] + tree[l+1][0];
	tree[pos][1] = tree[l][1] + tree[l+1][1];
}

void build(int pos, int lo, int hi){
	if( lo == hi ){
		tree[pos][0] = 1;
		return;
	}
	int mid = (lo+hi)/2;
	int l = 2*pos+1;
	build(l, lo, mid);
	build(l+1, mid+1, hi);
	tree[pos][0] = tree[l][0] + tree[l+1][0];
}

void update(int pos, int lo, int hi, int qlo, int qhi){
	int l = 2*pos+1;
	if( lazy[pos] )	prop(pos, lo, hi);		
	if( qlo > hi || qhi < lo ) return;
	if( qlo <= lo && qhi >= hi ){
		swap(tree[pos][0], tree[pos][1]);
		if( lo != hi ){
			lazy[l] = 1 - lazy[l];
			lazy[l+1] = 1 - lazy[l+1];
		}
		return;
	}
	int mid = (lo+hi)/2;
	update(l, lo, mid, qlo, qhi);
	update(l+1, mid+1, hi, qlo, qhi);
	merge(pos);	
}

int query(int pos, int lo, int hi, int qlo, int qhi){
	int l = 2*pos+1;
	if( lazy[pos] ){
		prop(pos, lo, hi);
	} 
	if( qlo > hi || qhi < 0 ) return 0;
	if( qlo <= lo && hi <= qhi ) return tree[pos][1];
	int mid = (lo+hi)/2;
	if( qlo > mid ) return query(l+1, mid+1, hi, qlo, qhi);
	else if( qhi <= mid ) return query(l, lo, mid, qlo, qhi); 
	int left = query(l, lo, mid, qlo, qhi);
	int right = query(l+1, mid+1, hi, qlo, qhi);
	return left+right;
}

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	build(0, 0, n-1);
	while(q--){
		int type, a, b;
		scanf("%d %d %d", &type, &a, &b);
		if( type )	printf("%d\n", query(0, 0, n-1, a-1, b-1));
		else{
			update(0, 0, n-1, a-1, b-1);
		}
	}		
}



