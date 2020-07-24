#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5+100;

char s[maxn];
int n,ans,q,x,T;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&q,&x);
		scanf("%s",s+1);
		int res = 0,res1=0;
		ans = 0;
		for(int i=1;i<=q;i++)
		{
			if(s[i]=='0') res++; 
			else res--;
		}
		if(x==0) ans++;
		if(res==0)
		{
			for(int i=1;i<=q;i++) 
			{
				if(s[i]=='0') res1++;
				else res1--;
				if(res1==x)  ans = -1;
			}
		}
		else 
		{
			for(int i=1;i<=q;i++)
			{
				if(s[i]=='0') res1++;
				else res1--;
				if((x-res1)%res==0&&(x-res1)/res>=0) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}