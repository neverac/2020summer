#include <stdio.h>
using namespace std;

int main()
{
	int T,k,L,sum,tmp=1e6;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&k,&L);
		if(L>=2000)
		{
			puts("-1");
			continue;
		}
		puts("1999");
		printf("-1 ");
		sum=1999+k;
		for(int i=0;i<1998;++i)
		{
			if(sum>=tmp)
			{
				printf("%d ",tmp);
				sum-=tmp;
			}
			else
			{
				printf("%d ",sum);
				sum=0;
			}
		}
		puts("");
	}
return 0;
}