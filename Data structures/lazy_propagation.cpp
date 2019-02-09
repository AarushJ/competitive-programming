vector<ll> v(N);
vector<ll> tree(4*N), lazy(4*N);
 
ll merge( ll left, ll right){
	ll tmp;
	// build temp from left and right according to quest
	return tmp;
}

void ulazy( ll pos, ll lo, ll hi, ll qlo, ll qhi, ll val){
	
	ll l = (pos<<1)+1, r = l+1;
	
	if( lazy[pos] ){	// if there are pending updates to current node
		
		// Here, add lazy[pos] effect to tree[pos](Current node)
			
		// lazy propagation to child nodes if they exist
		if( lo != hi ){		
			
		}	

		// clear lazy[pos]
		lazy[pos] = 0;
	}	
	
	if( lo > hi || lo > qhi || hi < qlo )
		return;
	
	if( qlo <= lo && hi <= qhi ){	// queried segment totally overlaps the current range of function
		
		// add effect of entire range to tree[pos]
		
		// Add lazy to child nodes if they exist
		if( lo != hi ){
			
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
		// Here, add lazy[pos] effect to tree[pos](Current node)
			
		// lazy propagation to child nodes if they exist	
		if( lo != hi ){		

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