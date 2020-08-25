#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

LL a[515][515],mp[515][515];

int n,m,k,x,y;
LL t, mod = 998244353; 

char op[4];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
			a[i][j]%=mod;
		}
	}
	LL ans =0;
	for(int i=1;i<=k;i++)
	{
		scanf("%s",op);		
		if(op[0]=='r')
		{
			scanf("%d%lld",&x,&t);
			t%=mod;
			for(int j=1;j<=m;j++)
			{
				ans = ans+a[x][j]*(t-mp[x][j]+mod)%mod;
				mp[x][j] = t;
			}
		}
		else
		{
			scanf("%d%lld",&y,&t);
			t%=mod;
			for(int j=1;j<=n;j++)
			{
				ans = ans+a[j][y]*(t-mp[j][y]+mod)%mod;
				mp[j][y] = t;
			}
		}
		ans%=mod;
	}
	printf("%lld\n", ans);
	return 0;
}