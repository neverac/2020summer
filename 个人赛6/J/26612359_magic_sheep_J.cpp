#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 4e5+100;

int n,k;
int a[maxn];

int main()
{
	scanf("%d%d",&n,&k);
	int ans =0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=(a[i]/k);
		if(a[i]%k) ans++;
	}
	int res = ans/2;
	if(ans&1) res++;
	printf("%d\n", res);
	return 0;
}