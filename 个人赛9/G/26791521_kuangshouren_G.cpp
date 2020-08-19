#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int to;node* next;
	long long pr;
};
struct good
{
	int co1,co2;
	long long pr;
};
node a[10];node* q[10];
int n,m;
good goods[200007];
int t[200007];
bool cmp(good A,good B)
{
	return A.pr<B.pr;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%lld",&goods[i].pr);
	for(int i=1;i<=n;++i)scanf("%d",&goods[i].co1);
	for(int i=1;i<=n;++i)scanf("%d",&goods[i].co2);
	sort(goods+1,goods+n+1,cmp);
	for(int i=1;i<=3;++i)q[i]=&a[i];
	for(int i=1;i<=n;++i)
	{
		int x=goods[i].co1,y=goods[i].co2;
		q[x]->next=new node;q[x]=q[x]->next;
		q[x]->to=i;q[x]->pr=goods[i].pr;q[x]->next=NULL;
		q[y]->next=new node;q[y]=q[y]->next;
		q[y]->to=i;q[y]->pr=goods[i].pr;q[y]->next=NULL;
	}
	for(int i=1;i<=3;++i)q[i]=&a[i];
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		int x;scanf("%d",&x);
		bool c=0;
		while(q[x]->next)
		{
			q[x]=q[x]->next;
			if(t[q[x]->to]==0)
			{
				c=1;
				t[q[x]->to]=1;
				printf("%lld ",q[x]->pr);
				break;
			}
		}
		if(c==0)printf("-1 ");
	}
	return 0;
}