#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int num[505],n,m,ans;
char data[20][505];

bool check()
{
	for(int i=0;i<n;++i)
		if(!num[i])
			return 0;
	return 1;
}

void DFS(int a,int count)
{
	if(a==m)
	{
		if(check())
			ans=min(ans,count);
		return ;
	}
	for(int i=0;i<n;++i)
		if(data[a][i]=='1')
			++num[i];
	DFS(a+1,count+1);
	for(int i=0;i<n;++i)
		if(data[a][i]=='1')
			--num[i];
	DFS(a+1,count);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(num,0,sizeof num);
		ans=0x3f3f3f3f;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)
		{
			getchar();
			for(int j=0;j<n;++j)
				scanf("%c",&data[i][j]);
		}
		DFS(0,0);
		if(ans==0x3f3f3f3f)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
return 0;
}