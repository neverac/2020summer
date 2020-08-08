#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
typedef int int_;

#define int long long
#define maxn 2000010
const int Mod=998244353;
const int inf=1e9+7;
const int p=998244353;
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
struct Edge{
	int u,v,w,next;
}E[maxn<<1];
int ecnt=0,head[maxn];
void addedge(int u,int v){
	E[++ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}
void Addedge(int u,int v){
	addedge(u,v);
	addedge(v,u);
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int ksm(int a,int b,int p){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret%p;
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int siz[maxn],fa[maxn];
void dfs(int x){
	siz[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		dfs(v);
		siz[x]+=siz[v];
	}
}
int Abs(int x){
	if(x<0) return -x;
	else return x;
}
struct P{
	int x,y;
}a[maxn],b[maxn];
char str[1010][1010];
int_ main(){
	int n=read(),m=read();
	int cnt=0,ct=0;
	for(int i=1;i<=n;++i){
		scanf("%s",str[i]+1);
		for(int j=1;j<=m;++j){
			if(str[i][j]=='1'){
				a[++cnt].x=i,a[cnt].y=j;
			}
			if(str[i][j]=='2'){
				b[++ct].x=i,b[ct].y=j;
			}
		}
	}
	int ans=n+m+2;
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=ct;++j){
			ans=min(ans,Abs(a[i].x-b[j].x)+Abs(a[i].y-b[j].y)+1);
		}
	}
	printf("%d",ans);
	return 0;
} 
/*
1
1 4
*/