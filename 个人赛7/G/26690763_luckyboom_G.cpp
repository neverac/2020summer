#include <bits/stdc++.h>
using namespace std;
int const maxn=1005,inf=1e9;
int  mp[maxn][maxn],dx[4]={0 ,1,0,-1},dy[4]={1,0,-1,0},n,m,tail=0,fr=0,mi;
bool vis[maxn][maxn];
struct po{
	int x,y,dis;
}gu[3],que[1000005];
int bfs(){
	int x,y,ux,uy,dis;
	
	//printf("hahah: %d %d\n",a,b );
	while(fr!=tail){
		x=que[++fr].x;y=que[fr].y;dis=que[fr].dis;
		// if(dis)
		// printf("%d %d\n",x,y );
		for(int i=0;i<4;i++){
			ux=x+dx[i],uy=dy[i]+y;
			if(ux<1||ux>n||uy<1||uy>m||vis[ux][uy])continue;
			if(mp[ux][uy]==2)return dis+1;
			que[++tail].x=ux,que[tail].y=uy;
			que[tail].dis=dis+1;
			vis[ux][uy]=1;
		}
	}
	return inf;
}
int main(){
	scanf("%d%d",&n,&m);
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=m;j++){
			mp[i][j]=s[j-1]-'0';
			if(mp[i][j]==1){
				gu[1].x=i;gu[1].y=j;
				que[++tail].x=i,que[tail].y=j;
				que[tail].dis=0;
				vis[i][j]=1;
			}
			else if(mp[i][j]==2){
				gu[2].x=i;gu[2].y=j;
			}
	}
	}
	mi=abs(gu[2].x-gu[1].x)+abs(gu[2].y-gu[1].y);
	mi=min(mi,bfs());

		
	printf("%d\n",mi+1);
	return 0;
}