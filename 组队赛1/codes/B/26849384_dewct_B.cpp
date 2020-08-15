#include <bits/stdc++.h>
using namespace std;
const int maxn=5010;

int n,a[maxn],dp[maxn][maxn],ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int l=i-1;
		for(int j=i+1;j<=n;j++){
			dp[i][j]=2;
			while(l>=1&&a[j]-a[i]>a[i]-a[l])--l;
			if(l>=1&&a[j]-a[i]==a[i]-a[l])dp[i][j]=max(dp[i][j],dp[l][i]+1);
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}