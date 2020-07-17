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
const ll M=26;
ll n;
char a[50];
int main(){
	scanf("%lld",&n);
	int op=0;
	while(n>0){
		op++;
		n-=1;
		a[op]=(n%M)+'a';
		n/=M;
	}
	for(int i=op;i>=1;i--) printf("%c",a[i]);
	return 0;
}