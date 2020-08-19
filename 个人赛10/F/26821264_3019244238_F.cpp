#include <stdio.h>
#include <algorithm>
using namespace std;

long long a[100050],tmp=1;

long long solve(int l,int r,long long depth)
{
	if(depth<0)
		return 0;
	long long mark=tmp<<depth;
	int mid=-1;
	for(int i=l;i<r;++i)
	{
		if(a[i]&mark)
		{
			mid=i;
			break;
		}
	}
	if(mid==-1 || mid==l)
		return solve(l,r,depth-1);
	return mark|min(solve(mid,r,depth-1),solve(l,mid,depth-1));
}

int main()
{
	long long ans;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	ans=solve(0,n,30);
	printf("%lld\n",ans);
return 0;
}