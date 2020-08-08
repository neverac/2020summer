#include <stdio.h>
#include <string.h>
using namespace std;

char str[100050];
int pos[26][100050];

int main()
{
	long long ans=0;
	int k,n,now;
	scanf("%d",&k);
	getchar();
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=0;i<26;++i)
	{
		now=0;
		for(int j=1;j<=n;++j)
		{
			if(str[j]-'a'==i)
				pos[i][++now]=j;
			if(!now)
				continue;
			if(now<=k)
				ans+=pos[i][now];
			else
				ans+=pos[i][now]-pos[i][now-k];
		}
	}
	printf("%lld\n",ans);
return 0;
}