#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int N=2e5+50;

struct Node
{
	int u,v;
	void input()
	{
		scanf("%d%d",&u,&v);
		if(u>v)
			swap(u,v);
	}
	bool operator<(const Node& t)const
	{
		if(t.v!=v)
			return v<t.v;
		return u<t.u;
	}
}edge[N];

int f[N],d[N];

int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}

bool merge(int x,int y)
{
	int xx=find(x);
	int yy=find(y);
	if(xx!=yy)
	{
		f[xx]=yy;
		return true;
	}
	return false;
}

void Init(int n)
{
	for(int i=1;i<=n;++i)
		f[i]=i;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Init(n);
	for(int i=1;i<=m;++i)
		edge[i].input();
	sort(edge+1,edge+1+m);
	for(int i=1;i<=m;++i)
	{
		int u=edge[i].u,v=edge[i].v;
		if(merge(u,v))
		{
			++d[u];
			++d[v];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(d[i],ans);
	printf("%d\n",ans);
return 0;
}