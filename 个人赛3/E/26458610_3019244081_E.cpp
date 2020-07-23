#include<bits/stdc++.h>
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 
*/
#define ll long long
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;

ll a[3][N];
ll dp[3][N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[0][i]);
	for(int i=1;i<=n;i++) scanf("%lld",&a[1][i]);
	dp[0][0]=0;
	dp[1][0]=0;
	for(int i=1;i<=n;i++){
		dp[0][i]=max(dp[0][i-1],dp[1][i-1]+a[0][i]);
		dp[1][i]=max(dp[1][i-1],dp[0][i-1]+a[1][i]);
	}
	printf("%lld",max(dp[0][n],dp[1][n]));
	return 0;
}