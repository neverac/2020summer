#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
	int x,y;
}one[1000050],two[1000050];

int main()
{
	int N,M,num_1=0,num_2=0,ans=0x3f3f3f3f;
	char a;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i)
	{
		getchar();
		for(int j=0;j<M;++j)
		{
			scanf("%c",&a);
			if(a=='1')
			{
				one[num_1].x=i,one[num_1].y=j;
				++num_1;
			}
			else if(a=='2')
			{
				two[num_2].x=i,two[num_2].y=j;
				++num_2;
			}
		}
	}
	for(int i=0;i<num_1;++i)
	{
		for(int j=0;j<num_2;++j)
		{
			ans=min(ans,abs(one[i].x-two[j].x)+abs(one[i].y-two[j].y)+1);
		}
	}
	printf("%d\n",ans);
return 0;
}