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
int ans[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1){
		for(int i=1;i<=n;i++) printf("%d ",i);
	}
	else{
		k++;
		for(int i=1;i<=n;i++) ans[i]=i;
		for(int i=1;i<=k;i++){
			if(i%2==1) ans[i]=(i+1)/2;
			else ans[i]=k+1-i/2;
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	return 0;
}