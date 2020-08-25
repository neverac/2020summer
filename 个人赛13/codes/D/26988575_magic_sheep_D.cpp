#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 3e5+100;


struct node
{
	int x,y;
};
node F[maxn];
int f[maxn];
bool cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

int n,m,x,y;

int find(int x)
{
	if(f[x]==x) return x;
	else return f[x] = find(f[x]);
}

int du[maxn];
void work()
{
	for(int i=1;i<=n;i++) f[i] = i,du[i]=0;
	for(int i=1;i<=m;i++)
	{
		int fx = find(F[i].x);
		int fy = find(F[i].y);
		x = F[i].x;
		y = F[i].y;
		if(fx==fy) continue;
		else{
			f[fx] =fy;
			du[x]++;
			du[y]++;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&F[i].x,&F[i].y);
		if(F[i].x<F[i].y) swap(F[i].x,F[i].y);
	}
	sort(F+1,F+1+m,cmp);
	int ans = 0;
	work();
	for(int i=1;i<=n;i++) ans = max(ans,du[i]);
	printf("%d\n", ans);
	return 0;
}