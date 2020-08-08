#include<iostream>
#include<cstdio>
using namespace std;
struct node
{int to;node* next;};
struct Node
{int l,r,lazy;
long long sum;};
Node tree[2000007];node a[500007];node* q[500007];
int idx[500007],top[500007],fa[500007],dep[500007],b[500007],size[500007],son[500007];
int bb[500007];
int n,m,root,tot;
void dfs1(int x,int f,int deep)
{
	fa[x]=f;dep[x]=deep;size[x]=1;
	int maxn=0,j=0;
	node* p=&a[x];
	while(p->next)
	{
		p=p->next;
		if(p->to!=fa[x])
		{
			dfs1(p->to,x,deep+1);
			size[x]+=size[p->to];
			if(size[p->to]>maxn)
			{maxn=size[p->to];j=p->to;}
		}
	}
	son[x]=j;
}
void dfs2(int x,int begin)
{
	++tot;idx[x]=tot;bb[tot]=b[x];
	top[x]=begin;
	if(son[x]!=0)dfs2(son[x],begin);
	node* p=&a[x];
	while(p->next)
	{
	p=p->next;
	if(p->to!=fa[x]&&p->to!=son[x])
	{dfs2(p->to,p->to);}
	}
}
void build(int lef,int righ,int x)
{
	tree[x].l=lef;tree[x].r=righ;
	tree[x].lazy=-1;
	if(lef==righ)
	{
		tree[x].sum=0;
		return;
	}
	build(lef,(lef+righ)>>1,x<<1);
	build((lef+righ)/2+1,righ,x<<1|1);
	tree[x].sum=0;
}
void pushdown(int x)
{
	if(tree[x].lazy==-1)return;
	tree[x<<1].lazy=tree[x].lazy;
	tree[x<<1|1].lazy=tree[x].lazy;
	tree[x<<1].sum=tree[x].lazy;
	tree[x<<1|1].sum=tree[x].lazy;
	tree[x].lazy=-1;
}
void update(int x,int lef,int righ,int y)
{
	if(tree[x].l>righ||tree[x].r<lef)return;
	if(tree[x].l>=lef&&tree[x].r<=righ)
	{tree[x].sum=y;
	tree[x].lazy=y;
	return;}
	pushdown(x);
	update(x<<1,lef,righ,y);
	update(x<<1|1,lef,righ,y);
	tree[x].lazy=-1;
}
long long look(int x,int lef,int righ)
{
	if(tree[x].l>righ||tree[x].r<lef)return 0;
	if(tree[x].l>=lef&&tree[x].r<=righ)return tree[x].sum;
	pushdown(x);
	return look(x<<1,lef,righ)+look(x<<1|1,lef,righ);
}
void work1(int x,int y,int z)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,idx[top[x]],idx[x],z);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	update(1,idx[y],idx[x],z);
}//gai
long long work2(int x,int y)
{
	long long sum=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		sum+=look(1,idx[top[x]],idx[x]);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	sum+=look(1,idx[y],idx[x]);
	return sum;
}//cha
int main()
{
	root=1;
	cin>>n;
	for(int i=1;i<=n;++i)q[i]=&a[i];
	for(int i=1;i<=n-1;++i)
	{
		int x,y;scanf("%d%d",&x,&y);
		q[x]->next=new node;q[x]=q[x]->next;
		q[x]->to=y;q[x]->next=NULL;
		q[y]->next=new node;q[y]=q[y]->next;
		q[y]->to=x;q[y]->next=NULL;
	}
	dfs1(root,root,1);
	dfs2(root,root);
	build(1,n,1);
	cin>>m;
	//update(1,idx[1],idx[1]+size[x])
	for(int i=1;i<=m;++i)
	{
		int x,t;
		scanf("%d%d",&t,&x);
		if(t==1){update(1,idx[x],idx[x]+size[x]-1,1);
		}
		if(t==2){work1(1,x,0);
		}
		if(t==3){printf("%lld\n",look(1,idx[x],idx[x]));}
	}
	return 0;
}