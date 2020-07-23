#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,h1[100010],h2[100010];
ll dp[3][100010],mx1=0,mx2=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h1[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&h2[i]);
	for(int i=1;i<=n;i++)
	{
		dp[1][i]=mx2+h1[i];
		dp[2][i]=mx1+h2[i];
		mx1=max(mx1,dp[1][i]);
		mx2=max(mx2,dp[2][i]);
	}
	printf("%lld",max(dp[1][n],dp[2][n]));
}