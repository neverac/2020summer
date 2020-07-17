#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,h;
int mp1[105][105];
int mp2[105][105];
int mp3[105][105];
int ans[105][105];
int sz[105][105][105];
int h1[105],h2[105];
int main()
{
	cin>>n>>m>>h;
	for(int i=1;i<=m;i++)
	{
		cin>>h1[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=h;j++)
		{
			if(j<=h1[i]) mp1[i][j] = 1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>h2[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=h;j++)
		{
			if(j<=h2[i]) mp2[i][j] = 1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp3[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=h;k++)
			{
				if(mp1[j][k]&&mp2[i][k]&&mp3[i][j])
				{
					sz[i][j][k]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=h;k++)
			{
				ans[i][j]+=sz[i][j][k];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}