#include<iostream>
#include<cstdio>
using namespace std;
long long a[100007],f[100007];
int n,T;
//aaa
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{f[i]=0;
		a[i]=0;}
		long long sum=0;
		long long maxn=0;
		for(int i=1;i<=n;++i)
		{
		scanf("%lld",&a[i]);
		sum+=a[i];
		}
		for(int i=1;i<=n-1;++i)
		{
			f[i]=max(f[i-1],(long long)0)+a[i];
			maxn=max(maxn,f[i]);
		}
		for(int i=1;i<=n;++i)f[i]=0;
		for(int i=2;i<=n;++i)
		{
			f[i]=max(f[i-1],(long long)0)+a[i];
			maxn=max(maxn,f[i]);
		}
		if(maxn<sum)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}