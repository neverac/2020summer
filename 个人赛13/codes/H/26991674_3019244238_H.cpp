#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long grass[505][505],mod=998244353;
long long col[505],row[505];

int main()
{
	memset(col,0,sizeof col);
	memset(row,0,sizeof row);
	memset(grass,0,sizeof grass);
	long long ans=0,t;
	int n,m,k,pos;
	char flag;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%lld",&grass[i][j]);
			grass[i][j]%=mod;
		}
	}
	while(k--)
	{
		getchar();
		scanf("%c%d%lld",&flag,&pos,&t);
		if(flag=='r')
			row[pos]=t;
		else
			col[pos]=t;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			ans=(ans+max(row[i],col[j])%mod*grass[i][j]%mod)%mod;
	printf("%lld\n",ans);
return 0;
}