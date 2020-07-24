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

ll k,n,s,p;
int main(){
	scanf("%lld%lld%lld%lld",&k,&n,&s,&p);
	ll ans=0;
	ans=(n+s-1)/s;
	ans*=k;
	ans=(ans+p-1)/p;
	printf("%lld",ans);
	return 0;
}