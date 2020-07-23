#include<iostream>
#include<cstdio>
using namespace std;
int a[10];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int x;scanf("%d",&x);
		++a[x]; 
	}
	if(a[1]==0)
	{
		for(int i=1;i<=n;++i)printf("2 ");
	}
	else if(a[2]==0)
	{
		for(int i=1;i<=n;++i)printf("1 ");
	}
	else
	{
		printf("2 1 ");
		for(int i=1;i<=a[2]-1;++i)printf("2 ");
		for(int i=1;i<=a[1]-1;++i)printf("1 ");
	}
	return 0;
}