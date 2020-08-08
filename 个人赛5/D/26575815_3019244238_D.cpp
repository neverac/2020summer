#include <stdio.h>
using namespace std;

int main()
{
	int t;
	long long n,k,ans,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		tmp=k%(n-1);
		ans=k/(n-1)*n+tmp;
		if(!tmp)
			--ans;
		printf("%lld\n",ans);
	}
return 0;
}