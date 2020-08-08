#include <bits/stdc++.h>
using namespace std;
int a[200100];
int dp1[200100],dp2[200100];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp1[0]=0;
	for (int i=1;i<=n;i++){
		if (a[i]>a[i-1]) dp1[i]=dp1[i-1]+1;
		else dp1[i]=1;
	}
	dp2[n]=1;
	for (int i=n-1;i>=1;i--){
		if (a[i]<a[i+1]) dp2[i]=dp2[i+1]+1;
		else dp2[i]=1;
	}
	int maxx=1;

	for (int i=2;i<n;i++){
		if (a[i-1]<a[i+1]) maxx=max(maxx,dp1[i-1]+dp2[i+1]);
		maxx=max(maxx,dp1[i-1]);
	} 
	maxx=max(maxx,dp1[n-1]);
	maxx=max(maxx,dp1[n]); 
	cout<<maxx<<endl;
	return 0;
}

