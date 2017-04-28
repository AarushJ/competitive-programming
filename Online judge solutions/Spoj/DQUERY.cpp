/*
	AARUSH JUNEJA
	@vivace
	IIT(ISM),Dhanbad
*/

#include<bits/stdc++.h>
using namespace std;

#define gc getchar
#define all(a) a.begin(),a.end()
#define lp(i,a,b) for(int i = int(a); i<=int(b) ; i++) 


int ip(){
	int x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc()); x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}

//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

#define MOD 1000000007
#define N 100010
#define MAX 1000005
int block;
int cnt[MAX], arr[N];

int ans;

struct query{
	int l,r,idx;
};

bool cmp(query a, query b){
	if(a.l/block != b.l/block)	return (a.l/block < b.l/block);
	return (a.r < b.r);
}

void add(int idx){
	cnt[arr[idx]]++;
	if(cnt[arr[idx]]==1)	++ans;
}

void rem(int idx){
	cnt[arr[idx]]--;
	if(!cnt[arr[idx]])	--ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,m,e,a,b,w,k;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
	
	cin >> n;
	block = sqrt(n);
	
	lp(i,0,n-1)	cin >> arr[i]; 
		
	int que;
	cin >> que;
	
	query q[que];
	int res[que];  
	
	lp(i,0,que-1){
		cin >> a >> b;
		a--; b--;
		q[i].l = a;	q[i].r = b;
		q[i].idx = i;
	}	
	
	sort(q,q+que, cmp);
	
	int cl  = 0, cr = 0;
	lp(i,0,que-1){
		int l = q[i].l, r = q[i].r;
		while(cl > l){
			add(cl-1);
			cl--;
		}
		
		while(cl < l){
			rem(cl);
			cl++;
		}
		
		while(cr <= r){
			add(cr);
			cr++;
		}
		
		while(cr > r+1){
			rem(cr-1);
			cr--;
		}
		
		res[q[i].idx] = ans;
	}
	
    lp(i,0,que-1){
    	cout << res[i] << "\n";
	}
    
	return 0;
}
