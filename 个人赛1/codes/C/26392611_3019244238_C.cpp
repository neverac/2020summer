#include <stdio.h>
using namespace std;

int p[100050],q[100050],num[100050];

int main()
{
	int t,n,mark;
	scanf("%d",&t);
	q[0]=0;
	while(t--)
	{
		mark=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			num[i]=0,p[i]=0;
			scanf("%d",&q[i]);
			if(q[i]<i)
				mark=1;
		}
		if(mark)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			num[q[i]]=1;
			if(q[i]>q[i-1])
				p[i]=q[i];
		}
		int k=1;
		for(int i=1;i<=n;++i)
		{
			if(!p[i])
			{
				for(;k<=n;++k)
				{
					if(!num[k])
					{
						p[i]=k;
						num[k]=1;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;++i)
			printf("%d ",p[i]);
		puts("");
	}
return 0;
}