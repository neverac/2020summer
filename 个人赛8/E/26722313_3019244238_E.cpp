#include <stdio.h>
using namespace std;

int main()
{
	long long a,sum,dp,Max;
	int t,n,l,r,L,R;
	scanf("%d",&t);
	while(t--)
	{
		sum=0,dp=0,Max=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&a);
			sum+=a;
			if(dp<=0)
			{
				dp=a;
				l=r=i;
			}
			else
			{
				dp+=a;
				r=i;
			}
			if(Max<dp)
			{
				Max=dp;
				L=l,R=r;
			}
		}
		if(sum>Max || (sum==Max && L==0 && R==n-1))
			printf("YES\n");
		else
			printf("NO\n");
	}
return 0;
}