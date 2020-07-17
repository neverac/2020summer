#include <bits/stdc++.h>
using namespace std;
int a[1100];
int main()
{
	int n,m;
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i = 1; i <= m; ++i) ans += a[i];
	printf("%d",ans);
	return 0;
} 