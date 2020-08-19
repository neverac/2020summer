#include <stdio.h>
#include <cmath>
using namespace std;

int visited[2050];

struct Point
{
	int x,y,z;
}point[2050];

int dis(Point a,Point b)
{
	return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
}

int main()
{
	int n,u,v,tmp,Min;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&point[i].x,&point[i].y,&point[i].z);
		visited[i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		if(visited[i])
			continue;
		u=0,v=0,Min=0x3f3f3f3f;
		for(int j=1;j<=n;++j)
		{
			if(visited[j] || j==i)
				continue;
			tmp=dis(point[i],point[j]);
			if(tmp<Min)
			{
				u=i,v=j;
				Min=tmp;
			}
		}
		if(u && v)
		{
			visited[u]=1,visited[v]=1;
			printf("%d %d\n",u,v);
		}
	}
return 0;
}