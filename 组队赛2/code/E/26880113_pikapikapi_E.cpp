#include<cstdio>
#include<algorithm>

using namespace std;

int l,k,num;
int main()
{
	int t,i;
	int v,v_;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&l);
		if(l>=2000)
		{
			printf("-1\n");
			continue;
		}
		printf("1999\n");
		for(v=3998-k%1999;v<1000000;v+=1999)
		{
			v_=(k+v)/1999;
			if(v_<v && -1997-v+v_>=-1000000)
			{
				printf("1 ");
				for(i=1;i<1997;i++)
				{
					printf("0 ");
				}
				printf("%d %d\n",-1-v+v_,v);
				//printf("%d\n",v);
				break;
			}
		}
	} 
	return 0;
}