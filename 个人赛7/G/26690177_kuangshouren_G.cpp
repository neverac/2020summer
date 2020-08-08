#include<iostream>
#include<cstdio>
using namespace std;
char a[1007][1007];
int f[1007];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",a[i]+1);
	}
	int maxn=0x3f3f3f3f;
		for(int i=1;i<=n;++i)
		{
		int now=0;
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]=='1')f[j]=i+j;
			now=max(now,f[j]);
			if(a[i][j]=='2')
			maxn=min(maxn,i+j-now+1);
		}
		}
		for(int i=1;i<=m;++i)f[i]=0;
		for(int i=1;i<=n;++i)
		{
		int now=0;
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]=='2')f[j]=i+j;
			now=max(now,f[j]);
			if(a[i][j]=='1')
			maxn=min(maxn,i+j-now+1);
		}
		}
		for(int i=1;i<=n;++i)
		{for(int j=1;j<=m/2;++j)swap(a[i][j],a[i][m-j+1]);}
		for(int i=1;i<=m;++i)f[i]=0;
				for(int i=1;i<=n;++i)
		{
		int now=0;
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]=='1')f[j]=i+j;
			now=max(now,f[j]);
			if(a[i][j]=='2')
			maxn=min(maxn,i+j-now+1);
		}
		}
		for(int i=1;i<=m;++i)f[i]=0;
		for(int i=1;i<=n;++i)
		{
		int now=0;
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]=='2')f[j]=i+j;
			now=max(now,f[j]);
			if(a[i][j]=='1')
			maxn=min(maxn,i+j-now+1);
		}
		}
		cout<<maxn;
		return 0;
}