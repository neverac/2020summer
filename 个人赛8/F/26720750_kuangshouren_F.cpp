#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[200007];
int n,T;
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		int maxn=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(char j='0';j<='9';++j)
		{
			for(char k='0';k<='9';++k)
			{
				int ans=0;
				bool c=1;
				for(int i=1;i<=n;++i)
				{
					if(c==1&&s[i]==j)
					{
						++ans;c=0;continue;
					}
					if(c==0&&s[i]==k)
					{
						++ans;c=1;continue;
					}
				}
				if(j!=k&&ans%2==1)--ans;
				maxn=max(maxn,ans);
			}
		}
		printf("%d\n",n-maxn);
	}
	return 0;
}