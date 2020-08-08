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

ll a[400];
ll dp[400];
int main(){
	int d;
	scanf("%d",&d);
	for(int i=1;i<=d;i++) scanf("%lld",&a[i]);
	a[0]=2147483647;
	dp[0]=100;
	for(int i=1;i<=d;i++){
		for(int j=0;j<i;j++){
			ll x=dp[j]/a[j];
			x=min(x,100000ll);
			dp[i]=max(dp[i],max( dp[j]-x*a[j]+x*a[i] ,dp[j] )    );
		}
	}
	printf("%lld",dp[d]);
	return 0;
}