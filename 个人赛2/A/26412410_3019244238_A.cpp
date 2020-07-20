#include <stdio.h>
#include <algorithm>
using namespace std;

int x[2550],mark[2550];

void Init(int num)
{
	for(int i=1;i<=num;i++)
		x[i]=i;
}

int find(int a)
{
	return x[a]==a?x[a]:x[a]=find(x[a]);
}

void Merge(int a,int b)
{
	int c=find(a),d=find(b);
	if(c!=d)
		x[c]=d;
}

int main()
{
	int m,n,a,num=0,Max=0;
	scanf("%d%d",&m,&n);
	Init(m*n);
	for(int i=1;i<=m*n;++i)
	{
		mark[i]=0;
		scanf("%d",&a);
		if(!(a>>0&1))
			Merge(i-1,i);
		if(!(a>>1&1))
			Merge(i,i-n);
		if(!(a>>2&1))
			Merge(i,i+1);
		if(!(a>>3&1))
			Merge(i+n,i);
	}
	for(int i=1;i<=m*n;++i)
		++mark[find(i)];
	for(int i=1;i<=m*n;++i)
	{
		if(mark[i])
		{
			++num;
			Max=max(Max,mark[i]);
		}
	}
	printf("%d\n%d\n",num,Max);
return 0;
}