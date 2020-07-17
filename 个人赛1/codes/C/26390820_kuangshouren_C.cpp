#include<iostream>
#include<cstdio>
using namespace std;
int a[100007],b[100007];
bool c[100007];
int T,n;
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		bool ccc=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{a[i]=0;
		c[i]=0;}
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&b[i]);
			if(b[i]<b[i-1])
			{ccc=1;break;}
			if(b[i]!=b[i-1])
			{c[b[i]]=1;
			a[i]=b[i];}
		}
		if(ccc==1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int j=1;
		for(int i=1;i<=n;++i)
		{
			if(a[i]==0)
			{
				while(c[j]==1)++j;
				a[i]=j;c[j]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			ans=max(a[i],ans);
			if(ans!=b[i])
			{ccc=1;break;}
		}
		if(ccc==1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			printf("%d ",a[i]);
		}
		cout<<endl;
	}
	return 0;
}