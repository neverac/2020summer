#include<bits/stdc++.h>

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 

#define ll long long
using namespace std;
const int N=1e5 + 100;
const double eps=1e-10;
int a[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=m;i++) ans+=a[i];
	printf("%lld",ans);
	return 0;
}