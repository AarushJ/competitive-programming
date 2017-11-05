vector<ll> v(N);
vector<ll> tree(4*N), lazy(4*N);
 
ll merge( ll left, ll right){
	ll tmp;
	tmp = left + right ;
	return tmp;
}

void ulazy( ll pos, ll lo, ll hi, ll qlo, ll qhi, ll val){
	
	ll l = (pos<<1)+1, r = l+1;
	
	if( lazy[pos] ){	// if there are pending updates to current node
		tree[pos] += (hi-lo+1)*lazy[pos];	
			
		if( lo != hi ){		
			lazy[l] += lazy[pos];
			lazy[r] += lazy[pos];
		}	
		
		lazy[pos] = 0;
	}	
	
	if( lo > hi || lo > qhi || hi < qlo )
		return;
	
	if( qlo <= lo && hi <= qhi ){	// queried segment totally overlaps the current range of function
		tree[pos] += (hi-lo+1)*val;
		if( lo != hi ){
			lazy[l] += val;
			lazy[r] += val;
		} 		
		return;
	}	
	
	ll mid = mid(lo,hi);
	
	ulazy( l, lo, mid, qlo, qhi, val);
	ulazy( r, mid+1, hi, qlo, qhi, val);
	
	tree[pos] = merge( tree[l], tree[r] );
	
}

ll qlazy( ll pos, ll lo, ll hi, ll qlo, ll qhi){
	
	ll l = (pos<<1)+1, r = l+1;
	
	if( lo > qhi || lo > hi || hi < qlo	)
		return 0;
	
	if( lazy[pos] ){	// if there are pending updates to current node
		tree[pos] += (hi-lo+1)*lazy[pos];	
			
		if( lo != hi ){		
			lazy[l] += lazy[pos];
			lazy[r] += lazy[pos];
		}	
		
		lazy[pos] = 0;
	}
	
	if( qlo <= lo && qhi >= hi )	// the segment of current node is completely inside queried range
		return tree[pos];
		
	ll mid = mid( lo , hi );
	
	if( qlo > mid)
		return qlazy( r, mid+1, hi, qlo, qhi);
	else if( qhi <= mid)
		return qlazy( l, lo, mid, qlo, qhi);
		
	ll left = qlazy( l, lo, mid, qlo, qhi);
	ll right = qlazy( r, mid+1, hi, qlo, qhi);	
		
	return merge( left, right);
}


/*	
	BEFORE EVERY TEST CASE
	
	lp(i, 4*n + 1){
			lazy[i] = 0;
			tree[i] = 0;	
	}

*/