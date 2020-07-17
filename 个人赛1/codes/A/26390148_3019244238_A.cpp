#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N,K,sum=0;
	int fruit[1050];
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;++i)
		scanf("%d",&fruit[i]);
	sort(fruit,fruit+N);
	for(int i=0;i<K;++i)
		sum+=fruit[i];
	printf("%d\n",sum);
return 0;
}