#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	long long n,m,x,y,num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
		if(y>=x)
			printf("%lld\n",m);
		else
		{
			num=min((n+(m-1)*y)/x,m);
			printf("%lld\n",num);
		}
	}
return 0;
}