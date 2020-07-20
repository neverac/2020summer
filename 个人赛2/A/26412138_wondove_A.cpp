#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define maxn 1000010
const int inf=1e9+7;
inline int read(){
	int ret=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-ff;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*ff;
}
int a[60][60];
int vis[60][60];
int dfs(int x,int y){
	int ret=0;
	vis[x][y]=1;
//	printf("%d %d %d %d\n",x,y,a[x][y],a[x][y]&1);
	if((a[x][y]&1)==0){	
		if(vis[x][y-1]==0){
			ret+=dfs(x,y-1);
		}
	}
	if((a[x][y]&2)==0){	
		if(vis[x-1][y]==0){
			ret+=dfs(x-1,y);
		}
	}
	if((a[x][y]&4)==0){	
		if(vis[x][y+1]==0){
			ret+=dfs(x,y+1);
		}
	}
	if((a[x][y]&8)==0){	
		if(vis[x+1][y]==0){
			ret+=dfs(x+1,y);
		}
	}
	return ret+1;
}
int_ main(){
	int n=read(),m=read();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	//printf("%d %d\n",a[1][1],a[1][1]&1);
	int ans=0,cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(vis[i][j]==0){
				ans=max(ans,dfs(i,j));
				++cnt;
			}
		}
	}
	printf("%lld\n%lld",cnt,ans);
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/