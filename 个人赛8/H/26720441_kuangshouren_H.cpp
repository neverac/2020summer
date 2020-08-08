#include<iostream>
#include<cstdio>
int a[200007];
int f[200007][2];
using namespace std;
int n;
int main()
{
	int maxn=0;
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	f[1][0]=1;f[1][1]=1;
	for(int i=2;i<=n;++i)
	{
		f[i][0]=1;f[i][1]=1;
		if(a[i-1]<a[i])
		{
			f[i][0]=max(f[i][0],f[i-1][0]+1);
			f[i][1]=max(f[i][1],f[i-1][1]+1);
		}
		if(a[i-2]<a[i])
		{
			f[i][1]=max(f[i][1],f[i-2][0]+1);
		}
		maxn=max(maxn,f[i][0]);
		maxn=max(maxn,f[i][1]);
	}
	cout<<maxn;
	return 0;
}