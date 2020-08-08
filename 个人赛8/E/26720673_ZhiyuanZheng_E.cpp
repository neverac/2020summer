#include <bits/stdc++.h>
using namespace std;
long long a[100100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		long long ans=0;
		long long dp=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			ans+=a[i];
		}
		long long maxx=0;
		for (int i=1;i<=n-1;i++){
			dp=max(a[i],dp+a[i]);
			maxx=max(maxx,dp);
		}
		dp=0;
		for (int i=2;i<=n;i++){
			dp=max(a[i],dp+a[i]);
			maxx=max(maxx,dp);
		}
		if (maxx>=ans) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}

