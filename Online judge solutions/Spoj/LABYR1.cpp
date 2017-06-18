#include<bits/stdc++.h>
using namespace std;

#define lp(i,a)	for(int i = (int)0 ; i < int(a) ; i++)

char g[1005][1005];
bool mark[1005][1005];
int dist[1005][1005];

void dfs(int parDist, int i, int j, int r, int c){
	if( g[i][j] != '.' || mark[i] [j]	|| i >= r || j >= c || i < 0 || j < 0 )	return;
	mark[i][j] = 1;
	dist[i][j] = parDist + 1;

	dfs(dist[i][j], i + 1, j, r, c);
	dfs(dist[i][j], i, j + 1, r, c);
	dfs(dist[i][j], i - 1, j, r, c);
	dfs(dist[i][j], i, j - 1, r, c);

}

int main(){
	int t, r, c;
	scanf("%d",&t);	
	while(t--){
		scanf("%d%d",&c,&r);
		int xx = -1,yy = -1;
		bool flag = false;
		lp(i,r){
			lp(j,c){
				scanf(" %c", &g[i][j]); 
				if( !flag && g[i][j] == '.' ){
					flag = true;
					xx = i, yy = j;
				}
			}
		}
	
		if( xx == -1 ){
			printf("Maximum rope length is 0.\n");
			continue;
		}
		
		dfs(0, xx, yy, r, c);
		int maxx = -1, xmax = -1, ymax = -1;
		lp(i,r){
			lp(j,c){
				if( dist[i][j] > maxx ){
					maxx = dist[i][j];
					xmax = i, ymax = j;
				}
				dist[i][j] = 0;
				mark[i][j] = 0;
			}
		}
		dist[xmax][ymax] = 0;
		dfs(0, xmax, ymax, r, c);
		maxx = -1;
		lp(i,r){
			lp(j,c){
				maxx = max(maxx, dist[i][j]);
			}
		}

		printf("Maximum rope length is %d.\n", maxx-1);

	}
		return 0;
}