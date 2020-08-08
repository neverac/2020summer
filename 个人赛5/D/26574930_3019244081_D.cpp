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
	int T;
	scanf("%d",&T);
	while(T--){
		ll n,k;
		scanf("%lld%lld",&n,&k);
		ll x=k/(n-1);
		ll xx=x*n;
		x*=(n-1);
		xx+=k-x;
		if(xx%n==0) xx-=1;
		printf("%lld\n",xx);
	}
	return 0;
}