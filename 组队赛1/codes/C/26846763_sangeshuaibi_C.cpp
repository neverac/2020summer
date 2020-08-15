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

int a[6*N];
int main(){
	int r,s,p,x,y;
	scanf("%d%d%d",&r,&s,&p);
	for(int i=1;i<=p;i++){
		scanf("%d%d",&x,&y);
		a[i]+=r-x;
		if(y<=s) a[i]+=s-y+1;
		else a[i]+=y-s;
	}
	sort(a+1,a+1+p);
	int cnt=0;
	for(int i=1;i<p;i++){
		if(a[i]==a[i+1]) cnt++;
		if(a[i+1]-a[i]>1) cnt=max(0,cnt-a[i+1]+a[i]+1);
	}
	printf("%d",a[p]+cnt+1);
	return 0;
}