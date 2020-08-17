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
	int n;
	ll x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		y=x*(x+1ll);
		printf("%lld\n",y^(x+1));
	}
	return 0;
}