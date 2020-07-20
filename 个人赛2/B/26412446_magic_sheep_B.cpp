#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int a,b,c,s;
bool mp[75535];
int f[80000],ans[30];
int main()
{
	while(1)
	{
		memset(mp,0,sizeof(mp));
		memset(ans,0,sizeof(ans));
		int cnt = 1;
		scanf("%d",&a);
		if(a==0&&scanf("%d%d%d",&b,&c,&s)==EOF) break;
		else scanf("%d%d%d",&b,&c,&s);
		mp[s]=true;
		f[cnt]=s;
		//cout<<a<<" "<<b<<" "<<c<<" "<<s<<endl;
		while(++cnt)
		{
			//cout<<cnt<<endl;

			int val = (a*s+b)%c;
			//cout<<val<<endl;
			if(mp[val]) break;
			else mp[val]=1,s=val;
			f[cnt] = val;
		}
		cnt--;
		for(int i=1;i<=cnt;i++)
		{
			for(int j=1;j<=16;j++)
			{
				if(f[i]&(1<<(j-1))) ans[j]++;
			}
		}
		for(int i=16;i>=1;i--)
		{
			if(ans[i]==cnt) printf("1");
			else if(ans[i]==0) printf("0");
			else printf("?");
		}
		puts("");
	}
	return 0;
}