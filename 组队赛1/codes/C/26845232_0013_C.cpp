#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a,b;
int d[500000];
int main()
{
	cin>>a>>b>>n;
	for(int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y>b)++y;
		d[i]=(a+1-x)+abs(y-b-1);
	}
	sort(d+1,d+n+1);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		++now;
		if(d[i]>now)now=d[i];
	}
	cout<<now;
	return 0;
}