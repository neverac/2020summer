#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 2e5+100;

int n;
int a[maxn],f[maxn][2];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) f[i][0] = 1,f[i][1] = 1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1]) f[i][0]=f[i-1][0]+1;
	}
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]<a[i+1]) f[i][1]=f[i+1][1]+1; 
	}
	int ans =0;
	for(int i=1;i<=n;i++)
	{
		ans = max(ans,f[i][0]);
		//cout<<f[i-1][0]<<" "<<f[i+1][1]<<endl;
		if(a[i+1]>a[i-1])ans = max(ans,f[i-1][0]+f[i+1][1]);
	}
	printf("%d\n", ans);
	return 0;
}