#include<cstdio>
#include<queue>
#include <cstring>
const int ud[4]={0,1,0,-1};
const int lr[4]={1,0,-1,0};
const int MAXN=1120;
int mp[MAXN][MAXN];
int dis[MAXN][MAXN];
int vis[MAXN][MAXN];
struct node {
	int x,y;
	node(int a=0,int b=0) {
		x=a;y=b;
	}
};
int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			scanf("%1d",&mp[i][j]); 
		}
	}
	std::queue<node>q;
	memset(dis,63,sizeof dis);
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			if(mp[i][j]==1) {
				dis[i][j]=1;
				vis[i][j]=1;
				q.push(node(i,j));
			}
		}
	}
	while(!q.empty()) {
		node o=q.front();q.pop();
		int x=o.x,y=o.y;vis[x][y]=0;
	//	printf("(%d,%d):=%d\n",x,y,dis[x][y]);
		for(int id=0;id<4;++id) {
			int xx=x+ud[id];
			int yy=y+lr[id];
			if(xx<1||xx>N||yy<1||yy>M)continue;
			if(dis[x][y]+1<dis[xx][yy]) {
				dis[xx][yy]=dis[x][y]+1;
				if(!vis[xx][yy]) {
					q.push(node(xx,yy));
					vis[xx][yy]=1;
				}
			}
		}
	}
	int ans=dis[0][0];
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			if(mp[i][j]==2) {
				ans=(ans<dis[i][j] ? ans:dis[i][j]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} 