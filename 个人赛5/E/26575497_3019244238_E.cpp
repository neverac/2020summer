#include <stdio.h>
#include <algorithm>
using namespace std;

long long ans=0;
int n,a[200050],trie[6000150][2],k=0;

void Insert(int x)
{
	int p=0;
	for(int i=29;i>=0;--i)
	{
		int c=(x>>i)&1;
		if(!trie[p][c])
			trie[p][c]=++k;
		p=trie[p][c];
	}
}

int query(int x)
{
	int p=0,ANS=0;
	for(int i=29;i>=0;--i)
	{
		int c=(x>>i)&1;
		if(trie[p][c])
			p=trie[p][c];
		else
		{
			p=trie[p][c^1];
			ANS|=(1<<i);
		}
	}
	return ANS;
}

void DFS(int l,int r,int deep)
{
	if(deep==-1 || l>=r)
		return ;
	int mid=l-1;
	while(mid<r && !((a[mid+1]>>deep)&1))
		++mid;
	DFS(l,mid,deep-1);
	DFS(mid+1,r,deep-1);
	if(mid==l-1 || mid==r)
		return ;
	for(int i=l;i<=mid;++i)
		Insert(a[i]);
	int tmp=0x3f3f3f3f;
	for(int i=mid+1;i<=r;++i)
		tmp=min(tmp,query(a[i]));
	ans+=(long long)tmp;
	for(int i=0;i<=k;++i)
		trie[i][0]=trie[i][1]=0;
	k=0;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	DFS(1,n,29);
	printf("%lld\n",ans);
return 0;
}