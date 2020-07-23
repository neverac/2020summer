#include <stdio.h>
using namespace std;

int main()
{
	int n,num_1=0,num_2=0,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&tmp);
		if(tmp==1)	++num_1;
		else		++num_2;
	}
	if(num_2 && num_1)
	{
		printf("2 1 ");
		--num_2,--num_1;
		for(int i=0;i<num_2;++i)
			printf("2 ");
		for(int i=0;i<num_1;++i)
			printf("1 ");
	}
	else
	{
		for(int i=0;i<num_1;++i)
			printf("1 ");
		for(int i=0;i<num_2;++i)
			printf("2 ");
	}
	puts("");
return 0;
}