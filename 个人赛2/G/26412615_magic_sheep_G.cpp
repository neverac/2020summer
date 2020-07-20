#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e5+100;

int n,k,op;
int ans[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=k+2;i<=n;i++) ans[i] = i;
	int cnt =1;
	for(int i=1;i<=k+1;i+=2)
	{
		ans[i] = cnt;
		cnt++;
	}
	cnt = k+1;
	for(int i=2;i<=k+1;i+=2)
	{
		ans[i] = cnt;
		cnt--; 
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	return 0;
}
