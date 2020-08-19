#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[200007];int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n*2;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+2*n+1);
	long long maxn=(long long)0x3f3f3f3f3f3f3f3f;
	maxn=min(maxn,(a[n]-a[1])*(a[n*2]-a[n+1]));
	long long x=a[n*2]-a[1];
	for(int i=2;i<=n;++i)
	{
		maxn=min(maxn,x*(a[i+n-1]-a[i]) );
	}
	cout<<maxn;
	return 0;
}