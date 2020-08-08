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

ll a[50],b[50],c[50];
void Init(){
	a[0]=1;
	b[0]=1;
	c[0]=1;
	for(int i=1;i<=32;i++) a[i]=a[i-1]*3;
	for(int i=1;i<=32;i++) a[i]+=a[i-1];
	for(int i=1;i<=32;i++) b[i]=b[i-1]*5;
	for(int i=1;i<=32;i++) b[i]+=b[i-1];
	for(int i=1;i<=32;i++) c[i]=c[i-1]*7;
	for(int i=1;i<=32;i++) c[i]+=c[i-1];
}
int main(){
	int n;
	ll x;
	Init();
	scanf("%d",&n);
	//ll y=1;
	//ll ans=0;
	/*while(y<=1000000000000000ll){
		y*=3;
		ans++;
	}
	printf("%lld",ans);*/  //32
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		while(x%2==0) x/=2;
		ll a3=0;
		while(x%3==0){
			x/=3;
			a3++;
		}
		ll a5=0;
		while(x%5==0){
			x/=5;
			a5++;
		}
		ll a7=0;
		while(x%7==0){
			x/=7;
			a7++;
		}
		printf("%lld\n",a[a3]*b[a5]*c[a7]);
	}
	return 0;
}