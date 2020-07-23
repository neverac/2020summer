#include <bits/stdc++.h>
using namespace std;
long long dp[100100][2];
long long h[100100][2];
long long b[100100][2];
int n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>h[i][0];
	for (int i=1;i<=n;i++)cin>>h[i][1];
	
	for (int i=1;i<=n;i++){
		for (int j=0;j<=1;j++){
			dp[i][j]=max(b[i-1][j^1]+h[i][j],b[i-1][j]);
		}
		for (int j=0;j<=1;j++){
			b[i][j^1]=max(b[i-1][j^1],dp[i][j^1]);
			b[i][j]=max(b[i-1][j],dp[i][j]);
		}
	}
	cout<<max(b[n][0],b[n][1])<<endl;
	return 0;
}
