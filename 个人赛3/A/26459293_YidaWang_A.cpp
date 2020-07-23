#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 500010
int read()
{
    int x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int n,m,uu,S,P,val[maxn];
   
struct Edgenode{int to,next,val,fr;}edge[maxn<<1];
int head[maxn<<1],cnt=1;
void add(int u,int v){cnt++;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;edge[cnt].fr=u;}
int dfn[maxn],low[maxn],qcnt,stack[maxn],top,num[maxn],belong[maxn],tot,sz[maxn],d[maxn];
bool vis[maxn];
bool toposort(){
	queue<int>q;
    for (int i=1; i<=n; i++){
    	if (!d[i]) q.push(i),vis[i]=1;
	}
	while (!q.empty()){
		int now = q.front(); q.pop();
		for (int i=head[now]; i; i=edge[i].next){
			int to = edge[i].to;
			d[to]--;
			if (!d[to]) q.push(to),vis[to]=1;
		}
	}
	for (int i=1; i<=n; i++) if (!vis[i]) return 1;
	return 0;
} 
int main()
{
    n=read(),m=read();
    for (int u,v,i=1; i<=m; i++) u=read(),v=read(),add(u,v),d[v]++;
	if (!toposort()){
		puts("1");
		for (int i=1; i<=m; i++) printf("1 ");
		puts("");
		return 0;
	}
	puts("2");
	for (int i=2; i<=cnt; i++){
		if (edge[i].fr<edge[i].to) printf("1 ");
		else printf("2 ");
	}
	puts("");
    return 0;
}