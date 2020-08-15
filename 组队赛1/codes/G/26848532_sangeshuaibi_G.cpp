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
int n;
int a[N],tree[N];
int ans[N];
int lowbit(int x){
	return x&(-x);
}
void add(int x){
	while(x<=N){
		tree[x]++;
		x+=lowbit(x);
	}
}
int sum(int x){
	int ret=0;
	while(x!=0){
		ret+=tree[x];
		x-=lowbit(x);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		add(a[i]);
		ans[i]=i-sum(a[i]);
	}
	/*for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);*/
	memset(tree,0,sizeof(tree));
	for(int i=n;i>=1;i--){
		add(a[i]);
		ans[i]=min(ans[i],n-i+1-sum(a[i]));
	}
	/*printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);*/
	ll p=0;
	//printf("\n");
	for(int i=1;i<=n;i++) p+=ans[i];
	printf("%lld",p);
	return 0;
}