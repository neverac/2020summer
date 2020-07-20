#include <cstdio>
#include <cmath>
#include <algorithm>
const int MAXN=60;
const int ud[]={0,-1,0,1};
const int lr[]={-1,0,1,0};
int w[MAXN][MAXN],vis[MAXN][MAXN];
int dfs(int x,int y) {
	vis[x][y]=1;
	int cnw=1;
	for(int id=0;id<4;++id) {
		if(!(w[x][y]&(1<<id))) {
			if(!vis[x+ud[id]][y+lr[id]]) {
				cnw+=dfs(x+ud[id],y+lr[id]);
			} 
		}
	}return cnw;
}
int doing() {
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			scanf("%d",&w[i][j]);
		}
	}
	int cnt=0,mx=0;
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			if(!vis[i][j]) {
				mx=std::max(dfs(i,j),mx);
				++cnt;
			}
		}
	}printf("%d\n%d\n",cnt,mx);
}
int main() {
	doing();
	return 0;
} 