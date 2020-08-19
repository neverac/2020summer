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

struct node{
	int v,id;
};
node a[150];
node b[150];
bool cmp1(node a,node b){
	if(a.v==b.v) return a.id<b.id;
	return a.v>b.v;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
int main(){
	int n,m,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		for(int j=1;j<=x;j++){
			//ans+=a[j].v;
			b[j]=a[j];
		}
		sort(b+1,b+1+x,cmp2);
		printf("%d\n",b[y].v);
	}
	return 0;
}