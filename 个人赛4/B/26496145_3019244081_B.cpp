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

char s[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int x=0;
	x=(s[n-1]-'0')*10+(s[n]-'0');
	if(x%4==0) printf("4");
	else printf("0"); 
	return 0;
}