#include<iostream>
#include<cstdio>
using namespace std;
int a[107][107][11],s[107][107][11];
int n,q,c;
int main()
{
	cin>>n>>q>>c;
	++c;
	for(int i=1;i<=n;++i)
	{
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		for(int j=0;j<c;++j)
		{
			a[x][y][j]+=(k+j)%c;
		}
	}
	for(int k=0;k<c;++k)
	{
		for(int i=1;i<=100;++i)
		{
			for(int j=1;j<=100;++j)
			{
				s[i][j][k]=a[i][j][k]+s[i-1][j][k]+s[i][j-1][k]-s[i-1][j-1][k];
			}
		}
	}
	for(int i=1;i<=q;++i)
	{
		int t,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		printf("%d\n",s[x2][y2][t%c]-s[x1-1][y2][t%c]-s[x2][y1-1][t%c]+s[x1-1][y1-1][t%c]);
	}
	return 0;
}