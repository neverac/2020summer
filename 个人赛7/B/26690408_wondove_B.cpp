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
int dfn[maxn],low[maxn];
int dindex=0;
int instack[maxn];
int stap[maxn];
int stop=0;
int belong[maxn];
int bcnt=0;
void tarjan(int v) {
	int u;//l = vec[v].size();
	dfn[v] = low[v] = ++dindex;
	instack[v] = true;
	stap[++stop] = v;
	for (int i = head[v]; i; i=E[i].next){
		u = E[i].v;
		if (!dfn[u]) {
			tarjan(u);
			if (low[u] < low[v])
				low[v] = low[u];
		}
		else if (instack[u] && dfn[u] < low[v])
			low[v] = dfn[u];
	}
	if (dfn[v] == low[v]) {
		bcnt++;
		do {
			u = stap[stop--];
			instack[u] = false;
			belong[u] = bcnt;
		}
		while (u != v);
	}
}
int vis[maxn];
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		if(vis[v]==0) dfs(v);
	}
}
int_ main(){
	int ans=0;
	int n=read(),m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		addedge(x,y);
	} 
	for(int i=1;i<=n;++i){
		if(vis[i]==0) dfs(i),ans=i;
	}
	for(int i=1;i<=n;++i) vis[i]=0;
	dfs(ans);
	for(int i=1;i<=n;++i){
		if(vis[i]==0){
			puts("0");
			return 0;
		}
	}
	
	tarjan(ans);
//	printf("%d",ans);
	int tmp=belong[ans],bns=0;
	for(int i=1;i<=n;++i){
	//	printf("%d ",belong[i]);
		if(belong[i]==tmp) ++bns;
	}
	printf("%lld\n",bns);
	return 0;
} 
/*
1
1 4
*/