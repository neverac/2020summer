#include <stdio.h>
using namespace std;

int main()
{
	long long a,b,c,tmp=0,ans=0;
	scanf("%lld%lld",&a,&b);
	if(a==b)
		printf("1\n");
	else
	{
		ans+=a/b;
		a%=b;
		while(1)
		{
			if(a==1)
			{
				ans+=b;
				break;
			}
			if(b==1)
			{
				ans+=a;
				break;
			}
			tmp+=b/a;
			b%=a;
			c=a,a=b,b=c;
		}
		ans+=tmp;
		printf("%lld\n",ans);
	}
return 0;
}