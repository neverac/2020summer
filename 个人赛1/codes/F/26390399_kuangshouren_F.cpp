#include<iostream>
#include<cstdio>
using namespace std;
long long a[100007];
int n,m;long long ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
	int x;
	scanf("%d",&x);
	++a[x];
	ans+=x;
	}
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		ans+=(y-x)*a[x];
		a[y]+=a[x];
		a[x]=0;
		printf("%lld\n",ans);
	}
	return 0;
	
}