#include <stdio.h>
#include <string.h>
using namespace std;

int Sum[15][105][105];

int main()
{
	memset(Sum,0,sizeof Sum);
	int n,q,c,t,x1,y1,x2,y2,x,y,s;
	scanf("%d%d%d",&n,&q,&c);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d",&x,&y,&s);
		for(int j=0;j<=c;++j)
			Sum[j][x][y]+=(s+j)%(c+1);
	}
	for(int i=0;i<=c;++i)
		for(int j=1;j<=100;++j)
			for(int k=2;k<=100;++k)
				Sum[i][j][k]+=Sum[i][j][k-1];
	for(int i=0;i<=c;++i)
		for(int j=1;j<=100;++j)
			for(int k=2;k<=100;++k)
				Sum[i][k][j]+=Sum[i][k-1][j];
	for(int i=0;i<q;++i)
	{
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		int ans,tmp=t%(c+1);
		ans=Sum[tmp][x2][y2]-Sum[tmp][x1-1][y2]-Sum[tmp][x2][y1-1]+Sum[tmp][x1-1][y1-1];
		printf("%d\n",ans);
	}
return 0;
}