#include<bits/stdc++.h>
using namespace std;
#define N 50005
typedef long long ll;
ll n,q;
struct node{
    ll sum,preSum,suffSum,maxSum;
};

node tree[4*N];
ll arr[N];

node merge(node l,node r){
	node res;
	
	res.sum 	= l.sum+r.sum;
	res.preSum 	= max(l.preSum, l.sum+r.preSum);
	res.suffSum = max(r.suffSum, l.suffSum + r.sum);
	res.maxSum 	= max(l.suffSum + r.preSum, max(l.maxSum,r.maxSum));
	
	return res;
	
}

void build(ll pos,ll lo,ll hi){
    if(lo==hi){
        tree[pos].sum = arr[lo];
        tree[pos].preSum = arr[lo];
        tree[pos].suffSum = arr[lo];
        tree[pos].maxSum = arr[lo];
		return;
	}
	
	ll mid = (lo+hi)>>1;
        
	ll left = (pos<<1)+1 , right = left+1;
		
	build(left,lo,mid);
    build(right,mid+1,hi);
        
    tree[pos] = merge(tree[left],tree[right]);
    
}

node query(ll pos,ll lo,ll hi,ll qlo,ll qhi){
	
    if(qlo<=lo && qhi>=hi)
    	return tree[pos];
    	
    ll mid = (lo+hi)>>1;
    	
	if(qlo > mid){
		return query( (pos<<1)+2, mid+1, hi, qlo, qhi);
	}else if(qhi <= mid){
		return query( (pos<<1)+1, lo, mid, qlo, qhi);
	}
		
	node left  =  query( (pos<<1)+1, lo, mid, qlo, qhi);
    node right =  query( (pos<<1)+2, mid+1, hi, qlo, qhi);
    	
    return merge(left,right);
    
}

int main(){
	ios::sync_with_stdio(false);
    cin >> n;    
    for(ll i=0 ; i<n ; i++)    cin >> arr[i];
    
	build(0,0,n-1);
    
    cin >> q;
    while(q--){
    	ll l,r;
    	cin >> l >> r;
    	node ans = query(0,0,n-1,l-1,r-1);
    	cout << ans.maxSum << "\n";
	}
        
    return 0;
}
