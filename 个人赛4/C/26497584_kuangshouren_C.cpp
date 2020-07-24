#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,x;
char s[100007];
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		s[0]='0';
		scanf("%d%d",&n,&x);
		scanf("%s",s+1);
		if(x<0)
		{
			x=-x;
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='0')s[i]='1';
				else s[i]='0';
			}
		}
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='0')++sum;
			else --sum;
		}
		if(sum==0)
		{
			int y=-1;bool c=0;
			for(int i=0;i<=n-1;++i)
			{
				if(s[i]=='0')++y;
				else --y;
				if(x==y)c=1;
			}
			if(c==1)
			{
				cout<<"-1"<<endl;continue;
			}
			else {
			cout<<"0"<<endl;
			continue;}
		}
		if(sum<0)
		{
			int ans=0;int y=-1;
			for(int i=0;i<=n-1;++i)
			{
				if(s[i]=='0')++y;
				else --y;
				if(y>=x&&y%(-sum)==x%(-sum))++ans;
			}
			cout<<ans<<endl;continue;
		}
		if(sum>0)
		{
			int ans=0;int y=-1;
			for(int i=0;i<=n-1;++i)
			{
				if(s[i]=='0')++y;
				else --y;
				if(y<=x&&(x-y)%sum==0)
				++ans;
			}
			cout<<ans<<endl;continue;
		}
	}
	return 0;
}