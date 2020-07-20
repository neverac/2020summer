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
struct Point{
	double x,y;
}p1,p2,p3,p[5];
bool cmp(Point t1,Point t2){
	return t1.x<t2.x;
}
char str[100010];
int_ main(){
	int T=read();
	for(int tt=1;tt<=T;++tt){
		long long ans=-1ll<<60;
		scanf("%s",str+1);
		int n=strlen(str+1);
		for(int i=3;i<=n-2;++i){
			int wqw=0;
			for(int j=i+2;j<=n;++j){
				wqw=wqw*10+str[j]-'0';
			}

			int qwq=((str[i]-'0')*(str[i+1]-'0'))/wqw;
			int ret=0;
			for(int j=1;j<=i-1;++j){
				ret=ret*10ll+str[j]-'0';
			}
			int qqqwq=0;
			for(int j=2;j<=i-1;++j){
				qqqwq=qqqwq*10ll+str[j]-'0';
			}
			int qwwq=max(ret/10ll+(ret%10),qqqwq+str[1]-'0');
		//	printf("%d %d\n",qqqwq,ret);
			ans=max(ans,qwwq-qwq);
			
		}
		printf("Case #%lld: %lld\n",tt,ans);
	}
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/