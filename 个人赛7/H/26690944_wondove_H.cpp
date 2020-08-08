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
int ans[maxn];
int_ main(){
	int n=read();
	int rt=0;
	for(int i=1;i<=n;++i){
		fa[i]=read();
		addedge(fa[i],i);
		if(fa[i]==0) rt=i;
	}
	int cnt=0;
	dfs(rt);
	for(int j=1;j<=n;++j){
		int qwq=n-siz[j];
		for(int i=head[j];i;i=E[i].next){
			int v=E[i].v;
			qwq=max(qwq,siz[v]);
		}
		if(n-qwq>qwq) ans[++cnt]=j;
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=cnt;++i){
		printf("%lld ",ans[i]);
	}
	return 0;
} 
/*
1
1 4
*/