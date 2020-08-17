#include <stdio.h>
using namespace std;

int main()
{
	long long n;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		printf("%lld\n",(n*(n+1))^(n+1));
	}
return 0;
}