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
ll cnt[N],a[N];
int main(){
	int n;
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ans+=a[i];
		cnt[a[i]]++;
	}
	int q;
	scanf("%d",&q);
	ll x,y;
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		cnt[y]+=cnt[x];
		ans+=(y-x) * cnt[x];
		cnt[x]=0;
		printf("%lld\n",ans);
	}
	return 0;
}