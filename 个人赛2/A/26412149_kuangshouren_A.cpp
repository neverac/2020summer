#include<iostream>
using namespace std;
int n,m;
int a[57][57];int f[57][57][4];
bool c[57][57];
int tot=0,maxn=0,ans=0;
void dfs(int x,int y)
{
	c[x][y]=1;++tot;
	if(y!=1&&f[x][y][0]==0&&c[x][y-1]==0)dfs(x,y-1);
	if(x!=1&&f[x][y][1]==0&&c[x-1][y]==0)dfs(x-1,y);
	if(y!=m&&f[x][y][2]==0&&c[x][y+1]==0)dfs(x,y+1);
	if(x!=n&&f[x][y][3]==0&&c[x+1][y]==0)dfs(x+1,y);
}
int main()
{
	cin>>n;cin>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int x;cin>>x;
			int h=0;
			while(x>0)
			{
				f[i][j][h]=x%2;
				x/=2;
				++h;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(c[i][j]==0)
			{
				tot=0;
				++ans;
				dfs(i,j);
				maxn=max(maxn,tot);
			}
		}
	}
	cout<<ans<<endl<<maxn;
	return 0;
}