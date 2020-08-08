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

char s[250];
int main(){
	int T;
	scanf("%d",&T);
	int n,x;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<=100;i++) s[i]='a';
		printf("%s\n",s);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			s[x]=s[x]=='a'?'b':'a';
			printf("%s\n",s);
		}
	}
	return 0;
}