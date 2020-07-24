#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

LL Pow(LL x,LL m)
{
	LL res = 1;
	while(m)
	{
		if(m&1) res=res*x;
		m>>=1;
		x=x*x;
	}
	return res;
}
char s[100100];

int main()
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	int res=0;
	if(n==1)res = s[n]-'0';
	if(n>1) res = (s[n-1]-'0')*10+s[n]-'0';
	if(res%4==0) puts("4");
	else puts("0");
	return 0;
}