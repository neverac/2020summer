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
#define inf 2147483647
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
	int T;
	scanf("%d",&T);
	int n,a,b;
	for(int j=1;j<=T;j++){
		scanf("%d%d%d",&n,&a,&b);
		int x=gcd(a,b);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(i%x==0) cnt++;
		}
		printf("Case #%d: ",j);
		if(cnt%2==0) printf("Iaka\n");
		else printf("Yuwgna\n");
	}
	return 0;
}