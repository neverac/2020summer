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

int a[500];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	int mn=361;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mn=min(mn,2*abs(180-(360-(a[j]-a[i]))));
		}
	}
	printf("%d",mn);
	return 0;
}