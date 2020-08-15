#include <bits/stdc++.h>
using namespace std;
int a[5010],dp[5010][5010];
int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		int index=i-1;
		for(int j=i+1;j<=n;j++)
		{
			while(index>=1&&a[j]-a[i]>a[i]-a[index])
			index--;
			if(index>=1&&a[j]-a[i]==a[i]-a[index])
			dp[i][j]=max(2,dp[index][i]+1);
			else
			dp[i][j] = 2;
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}