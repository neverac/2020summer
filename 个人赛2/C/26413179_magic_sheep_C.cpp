#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define LL long long 
using namespace std;

int T,n;
char s[100];
LL a,b,c,d;
LL work1(int x,int y)
{
	LL ans = 0;
	for(int i=x;i<=y;i++)
	{
		LL res = s[i]-'0';
		ans=ans*10ll+res;
	}

	return ans;
}

int main()
{
	int st = 0;
	scanf("%d",&T);
	while(T--)
	{
		st++;
		scanf("%s",s+1);
 		n = strlen(s+1);
 		LL ans=-1e10;
 		for(int i=2;i<=n-3;i++)
 		{
 			a = max(work1(2,i)+work1(1,1),work1(1,i-1)+work1(i,i));
 			c = work1(i+1,i+1)*work1(i+2,i+2);
 			d= work1(i+3,n);
 			ans = max(ans,a-c/d);
 		}
 		printf("Case #%d: %lld\n",st, ans);
	}
	return 0;
}
/*
1000
12345678
55555
 */