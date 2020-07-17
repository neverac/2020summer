#include <stdio.h>
using namespace std;

int num[100050];

int main()
{
	long long sum=0;
	int N,Q,B,C,a;
	scanf("%d",&N);
	for(int i=0;i<100050;++i)
		num[i]=0;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&a);
		sum+=(long long)a;
		++num[a];
	}
	scanf("%d",&Q);
	for(int i=0;i<Q;++i)
	{
		scanf("%d%d",&B,&C);
		sum+=(long long)(C-B)*num[B];
		num[C]+=num[B];
		num[B]=0;
		printf("%lld\n",sum);
	}
return 0;
}