#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#define N 100

using namespace std;

int color[N][N];
int room[N][N];
int maxrooms;
int roomnum;
int rooms;

void dfs(int i,int j)
{
	if(color[i][j])
	  return ;
	rooms++;
	color[i][j]=roomnum;
	if((room[i][j]&1)==0)
        dfs(i,j-1);
	if((room[i][j]&2)==0)
        dfs(i-1,j);
	if((room[i][j]&4)==0)
        dfs(i,j+1);
	if((room[i][j]&8)==0)
        dfs(i+1,j);
}
int main()
{
    int i,j;
	int h,l;
	scanf("%d%d",&h,&l);
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=l;j++)
		{
			scanf("%d",&room[i][j]);
		}
	}
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=l;j++)
		{
			if(!color[i][j])
			{
rooms=0;
				roomnum++;	
				dfs(i,j);
				maxrooms=max(rooms,maxrooms);
			}
		}
	}
    printf("%d\n%d\n",roomnum,maxrooms);
	return 0;
}
