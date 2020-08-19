#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node
{
	int data,ID;
}node[105],tmp[105];

bool cmp1(Node a,Node b)
{
	if(a.data==b.data)
		return a.ID<b.ID;
	return a.data>b.data;
}

bool cmp2(Node a,Node b)
{
	return a.ID<b.ID;
}

int main()
{
	int n,m,k,pos;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&node[i].data);
		node[i].ID=i;
	}
	sort(node,node+n,cmp1);
	scanf("%d",&m);
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&k,&pos);
		for(int i=0;i<k;++i)
			tmp[i]=node[i];
		sort(tmp,tmp+k,cmp2);
		printf("%d\n",tmp[pos-1].data);
	}
return 0;
}