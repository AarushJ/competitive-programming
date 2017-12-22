ll bit[N];

void update(int i, int val){
	while( i < N ){
		bit[i] += val;
		i += (i&-i);
	}
}

ll getsum(int i){ 
	ll sum = 0;
	while( i > 0 ){
		sum += bit[i];
		i -= (i&-i);
	}
	return sum;
}
