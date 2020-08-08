#include <stdio.h>
using namespace std;

int main()
{
	long long n,k,w,sum=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&w);
		sum+=w/k+!!(w%k);
	}
	printf("%lld\n",sum/2+!!(sum&1));
return 0;
}