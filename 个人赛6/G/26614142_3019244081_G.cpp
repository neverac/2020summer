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

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll x=gcd(a,b);
	a/=x;
	b/=x;
	ll ans=0;
	if(a==b){printf("1"); return 0;}
	if(a>b){ans+=a/b;a%=b;}
	while(1){
		if(a==1){
			ans+=b;
			break;
		}
		if(b==1){
			ans+=a;
			break;
		}
		ll x=b/a;
		ans+=x;
		b%=a;
		swap(a,b);
	}
	printf("%lld",ans);
	return 0;
}