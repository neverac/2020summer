#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;
int n;
long long  a[maxn];
long long dp[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long  sum=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		dp[0]=0;
		bool ans=true;;
		for(int i=1;i<n;i++){
			dp[i]=max(dp[i-1]+a[i],a[i]);
			if(dp[i]>=sum)ans=false;
		}
		dp[1]=0;
		for(int i=2;i<=n;i++){
			dp[i]=max(dp[i-1]+a[i],a[i]);
			if(dp[i]>=sum)ans=false;
		}
		if(ans)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}