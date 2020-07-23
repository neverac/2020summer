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
const int N=2e5 + 100;
const double eps=1e-10;
int main(){
	int n,x;
	scanf("%d",&n);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x==1) cnt1++;
		else cnt2++;
	}
	if(cnt2>0 && cnt1>0){printf("2 1 ");cnt2--;cnt1--;}
	for(int i=1;i<=cnt2;i++) printf("2 ");
	for(int i=1;i<=cnt1;i++) printf("1 ");
	return 0;
}