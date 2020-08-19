#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int visited[200050],num[5],now[5];

struct Shirt
{
	int p,a,b;
	int ID;
}shirt[200050],tmp[5][200050];

bool cmp(Shirt a,Shirt b)
{
	return a.p<b.p;
}

int main()
{
	memset(num,0,sizeof num);
	memset(now,0,sizeof now);
	memset(visited,0,sizeof visited);
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&shirt[i].p);
		shirt[i].ID=i;
	}
	for(int i=0;i<n;++i)
		scanf("%d",&shirt[i].a);
	for(int i=0;i<n;++i)
		scanf("%d",&shirt[i].b);
	for(int i=0;i<n;++i)
	{
		tmp[shirt[i].a][num[shirt[i].a]++]=shirt[i];
		if(shirt[i].b!=shirt[i].a)
			tmp[shirt[i].b][num[shirt[i].b]++]=shirt[i];
	}
	sort(tmp[1],tmp[1]+num[1],cmp);
	sort(tmp[2],tmp[2]+num[2],cmp);
	sort(tmp[3],tmp[3]+num[3],cmp);
	scanf("%d",&m);
	for(int t=0;t<m;++t)
	{
		int c;
		scanf("%d",&c);
		if(now[c]>=num[c])
		{
			printf("-1 ");
			continue;
		}
		int ii;
		for(ii=now[c];ii<num[c];++ii)
		{
			int id=tmp[c][ii].ID;
			if(visited[id])
				continue;
			printf("%d ",tmp[c][ii].p);
			visited[id]=1;
			now[c]=ii+1;
			break;
		}
		if(ii==num[c])
		{
			now[c]=num[c];
			printf("-1 ");
		}
	}
	puts("");
return 0;
}