#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2][100010],a[100010],b[100010];

int main()
{
    ll n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    scanf("%lld",&a[i]);
    
    for(int i=0;i<n;i++)
    scanf("%lld",&b[i]);
    
    dp[0][0]=a[0];
    dp[1][0]=b[0];
    
    for(int i=1;i<n;i++)
    {
    	dp[0][i]=max(dp[0][i-1],dp[1][i-1]+a[i]);
    	dp[1][i]=max(dp[1][i-1],dp[0][i-1]+b[i]);
	}
	
	ll ans =max(dp[0][n-1],dp[1][n-1]);
	printf("%lld\n",ans);
    
	return 0;
} 