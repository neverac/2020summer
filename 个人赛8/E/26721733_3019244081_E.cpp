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

int a[N];
int main(){
	int T;
	scanf("%d",&T);
	int n;
	bool sp;
	while(T--){
		sp=false;
		ll sum=0ll;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			//if(a[i]<0) allp=false;
			sum+=a[i];
		}
		ll now=0ll;
		ll mx=0ll;
		for(int i=1;i<n;i++){
			if(now+a[i]<=0){
				now=0;
				sp=true;
				continue;
			}
			now+=a[i];
			mx=max(mx,now);
			//printf("?%lld   ",mx);
		}
		if(a[n]<0){
			sp=true;
		}
		else if(sp){
			now+=a[n];
			mx=max(mx,now);
		}
		else{
			now=0ll;
			for(int i=2;i<=n;i++){
				if(now+a[i]<=0){
					now=0;
					continue;
				}
				now+=a[i];
				mx=max(mx,now);
			}
		}
		//printf("%lld  %lld\n",sum,mx);
		if(sum>mx) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}