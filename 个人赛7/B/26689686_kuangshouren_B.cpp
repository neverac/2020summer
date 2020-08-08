#include<iostream>
#include<cstdio>
using namespace std;
struct node
{int to;node* next;};
node a[100007],b[100007];node* q[100007];node* qq[100007];bool v[100007];
int f[100007],f2[100007],f3[100007];int n,m,_clock_,top,s_clock_;
int dfn[100007],low[100007],stack[100007],scc[100007],degree[100007],queue[100007];
bool vv[100007];
int kfc;
void dfs2(int x)
{
	v[x]=1;++kfc;
	node* p=&a[x];
	while(p->next)
	{
		p=p->next;
		if(v[p->to]==0)
		dfs2(p->to);
	}
}
void dfs(int x)
{++top;++_clock_;
dfn[x]=low[x]=_clock_;
stack[top]=x;v[x]=1;
node* p=&a[x];
while(p->next)
{p=p->next;
if(dfn[p->to]==0)
{dfs(p->to);low[x]=min(low[x],low[p->to]);}
else
{if(v[p->to]==1)low[x]=min(low[x],low[p->to]);}}
if(dfn[x]==low[x])
{++s_clock_;int y;
do
{y=stack[top];
f2[s_clock_]+=f[y];
scc[y]=s_clock_;v[y]=0;
--top;}
while(x!=y);}
}
int main()
{
cin>>n>>m;
for(int i=1;i<=n;++i)
{q[i]=&a[i];qq[i]=&b[i];f[i]=1;}
for(int i=1;i<=m;++i)
{int x,y;scanf("%d%d",&x,&y);
q[x]->next=new node;q[x]=q[x]->next;
q[x]->to=y;q[x]->next=NULL;}
dfs2(1);
if(kfc!=n)
{
	cout<<"0";
	return 0;
}
for(int i=1;i<=n;++i){if(dfn[i]==0)dfs(i);}
for(int i=1;i<=n;++i)
{int u=scc[i];
node* p=&a[i];
while(p->next)
{p=p->next;
int k=scc[p->to];
if(u!=k)
{++degree[k];
qq[u]->next=new node;qq[u]=qq[u]->next;
qq[u]->to=k;qq[u]->next=NULL;}}}
int head=0,tail=0;
int ggg=0,hhh=0;
for(int i=1;i<=s_clock_;++i)
{if(degree[i]==0)
{++ggg;hhh=f2[i];}}
if(ggg==1)
cout<<hhh;
else
cout<<"0";
return 0;
}