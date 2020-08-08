#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 4e5+100;

int n,k,a,b;
int f[maxn];

int find(int x)
{
	if(f[x]==x) return x;
	else return f[x] = find(f[x]);
}

int main()
{
	int res = 0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) f[i] = i;

	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&a,&b);
		int fa = find(a);
		int fb = find(b);
		if(fa!=fb) f[fa] = fb,res++;
		//cout<<"I:: "<<i<<endl;
	}
	res = k-res;
	printf("%d\n", res);
	return 0;
}