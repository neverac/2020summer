#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000],sum[1000];

int main()
{
	sum[0]=0;
	int n,cmp1,cmp2,ans=0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;++i)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=i+n-1;++j)
		{
			cmp1=sum[j]-sum[i-1];
			cmp2=360-cmp1;
			ans=min(ans,abs(cmp1-cmp2));
		}
	}
	printf("%d\n",ans);
return 0;
}