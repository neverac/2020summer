#include <stdio.h>
#include <string.h> 
#include <algorithm>
using namespace std;

int now[100050];
int n,a[100050],c[100050];

int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int d)
{
	for(int i=x;i<=100000;i+=lowbit(i))
		c[i]+=d;
}

int getsum(int x)
{
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

int main()
{
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		update(a[i],1);
		now[i]=i-getsum(a[i]);
	}
	memset(c,0,sizeof c);
	for(int i=n;i>=1;--i)
	{
		update(a[i],1);
		ans+=min(now[i],n-i+1-getsum(a[i]));
	}
	printf("%lld\n",ans);
return 0;
}