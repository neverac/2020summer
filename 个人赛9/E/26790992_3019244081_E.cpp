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
/*ll euler[10*N];
void Init_euler(){
	for(int i=1;i<=1e6;i++) euler[i]=i;
	for(int i=2;i<=1e6;i++){
		if(euler[i]==i){
			for(int j=i;j<=1e6;j+=i){
				euler[j]=euler[j]/i*(i-1);
			}
		}
	}
	for(int i=3;i<=1e6;i++) euler[i]+=euler[i-1];//Ç°×ººÍ 
}*/ 
inline long long Eular(long long n)
{
	long long ans=n;
	for(ll i=2; 1ll*i*i<= n; i++)
	{
		if(n%i==0)
		{
			ans-=ans/i;
			while(n%i==0)
				n/=i;
		}
	}
	if(n>1)
		ans-=ans/n;
	return ans;
}
int main(){
	ll T;
	ll a,m;
	scanf("%lld",&T); 
	while(T--){
		scanf("%lld%lld",&a,&m);
		int g=gcd(a,m);
		m/=g;
		printf("%lld\n",Eular(m));
	}

	return 0;
}