#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=3000;
int f[12][105][105];
int op,n,cur;
int low(int x)
{
	return x&(-x);
}
int add(int id,int x,int y,int k)
{
	for(int i=x;i<=100;i+=low(i))
	{
		for(int j=y;j<=100;j+=low(j))
		{
			f[id][i][j]+=k;
		}
	}
}
int sum(int id,int x,int y)
{
	int ans=0;
	for(int i=x;i;i-=low(i))
	{
		for(int j=y;j;j-=low(j))
		{
			ans+=f[id][i][j];
		}
	}
	return ans;
}
int x,y,z;
int l,r,t,b;
int q,c,ID;
int main()
{
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		for(int j=0;j<=c;j++)
		{
			int res = (j+z)%(c+1);
			add(j,x,y,res);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d",&ID,&r,&t,&l,&b);
		int X1 = min(r,l);
		int X2 = max(r,l);
		int Y1 = min(t,b);
		int Y2 = max(t,b);
		ID%=(c+1);
		//cout<<X1<<" "<<Y1<<" "<<X2<<" "<<Y2<<endl;
		cur=sum(ID,X2,Y2)-sum(ID,X1-1,Y2)-sum(ID,X2,Y1-1)+sum(ID,X1-1,Y1-1);
		//for(int j=0;j<=c;j++)
		//cout<<sum(j,X2,Y2)<<endl;
		printf("%d\n",cur);
	}
	return 0;
}