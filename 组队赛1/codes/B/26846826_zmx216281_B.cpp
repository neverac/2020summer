#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int a[N],dp[N][N];
signed main(){
    int n,p;
    int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
	    scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			p=lower_bound(a+1,a+1+n,2*a[j]-a[i])-a;
			if(a[p]+a[i]==2*a[j]){
			    dp[i][j]=max(dp[i][j],dp[j][p]+1);
			}	
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans+2<< endl;
}
