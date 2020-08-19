#include <bits/stdc++.h>
using namespace std;
int a[400],sum[400]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		sum[i]=sum[i-1]+x;
	}
	int ans=360;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			ans=min(ans,abs((360-sum[j]+sum[i-1])-(sum[j]-sum[i-1])));
		}
	}
	cout<<ans<<endl;
	return 0;
}

