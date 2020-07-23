#include <stdio.h>
#include <algorithm>
using namespace std;

long long h1[100050],h2[100050];
long long dp[2][100050];

int main()
{
	long long ans;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&h1[i]);
	for(int i=1;i<=n;++i)
		scanf("%lld",&h2[i]);
	for(int i=1;i<=n;++i)
	{
		dp[0][i]=max(dp[0][i-1],dp[1][i-1]+h1[i]);
		dp[1][i]=max(dp[1][i-1],dp[0][i-1]+h2[i]);
	}
	ans=max(dp[0][n],dp[1][n]);
	printf("%lld\n",ans);
return 0;
}