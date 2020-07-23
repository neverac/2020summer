#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int maxn = 100010;
ll f[maxn][3],g[maxn];
int a[maxn],b[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	for(int i=n;i>=1;i--){
		f[i][1]=a[i]+max(f[i+1][2],g[i+2]);
		f[i][2]=b[i]+max(f[i+1][1],g[i+2]);
		g[i]=max(f[i][1],f[i][2]);
	}
	printf("%lld\n",g[1]);
}