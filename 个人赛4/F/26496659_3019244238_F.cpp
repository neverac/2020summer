#include <stdio.h>
using namespace std;

int main()
{
	int k,n,s,p;
	scanf("%d%d%d%d",&k,&n,&s,&p);
	int tmp=k*(n/s+!!(n%s));
	int ans=tmp/p+!!(tmp%p);
	printf("%d\n",ans);
return 0;
}