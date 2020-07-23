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
	char x;
	scanf("%d",&n);
	scanf("%c",&x);
	//printf("%c",x);
	int a=0;
	int mn=0;
	for(int i=1;i<=n;i++){
		scanf("%c",&x);
		if(x=='+'){
			a++;
		}
		else{
			a--;
			mn=min(mn,a);
		}
	}
	printf("%d",a-mn);
	return 0;
}