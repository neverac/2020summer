#include <stdio.h>
#include <algorithm>
using namespace std;

long long a[200050];

int main()
{
	long long Min=0x3f3f3f3f,ans,cmp;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+2*n);
	for(int i=2;i<=n;++i)
		Min=min(Min,a[i+n-1]-a[i]);
	ans=Min*(a[2*n]-a[1]);
	cmp=(a[2*n]-a[n+1])*(a[n]-a[1]);
	ans=min(ans,cmp);
	printf("%lld\n",ans);
return 0;
}