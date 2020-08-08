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

int a[N],b[N];
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	int i=1,j=1;
	while(1){
		if(a[i]<b[j]){
			i++;
		}
		else{
			j++;
		}
		if(i>n || j>n) break;
	}
	if(i>n) ans=n-j+1;
	else ans=n-i+1;
	printf("%d",ans);
	return 0;
}