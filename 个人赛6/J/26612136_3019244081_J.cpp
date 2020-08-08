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


int main(){
	int n,k,x;
	scanf("%d%d",&n,&k);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		ans+=(x+k-1)/k;
	}
	printf("%d",(ans+1)/2);
	return 0;
}