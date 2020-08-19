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
int a[2*N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n+n);
	//for(int i=1;i<=2*n;i++) printf("%d ",a[i]);
	ll x=a[n]-a[1];
	ll y=a[2*n]-a[n+1];
	ll mn=x*y;
	x=a[2*n]-a[1];
	for(int i=2;i<=n;i++){
		y=a[i+n-1]-a[i];
		mn=min(mn,x*y);
	}
	printf("%lld",mn);
	return 0;
}