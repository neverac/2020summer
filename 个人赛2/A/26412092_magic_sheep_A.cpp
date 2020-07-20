#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n,m,cnt,mx,res;
int a[105][105];
int vis[105][105];

void dfs(int x,int y)
{
	res++;
	if(!vis[x][y+1]&&(a[x][y]&4)==0) vis[x][y+1]= cnt,dfs(x,y+1);
	if(!vis[x+1][y]&&(a[x][y]&8)==0) vis[x+1][y]= cnt,dfs(x+1,y);
	if(!vis[x][y-1]&&(a[x][y]&1)==0) vis[x][y-1]= cnt,dfs(x,y-1);
	if(!vis[x-1][y]&&(a[x][y]&2)==0) vis[x-1][y]= cnt,dfs(x-1,y);
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(vis,1,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			vis[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j])
			{
				res= 0;
				cnt++;
				vis[i][j] = cnt;
				dfs(i,j);
				mx = max(res,mx);
			}
		}
	}
	printf("%d\n%d\n",cnt,mx);
	return 0;
}