#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int read()
{
    int x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
#define INF 0x7fffffff
#define MAXN 500010
#define LL long long
int N,Q;
struct EdgeNode{int next,to;}edge[MAXN<<1];
int cnt=1,head[MAXN];
inline void AddEdge(int u,int v) {cnt++; edge[cnt].next=head[u]; head[u]=cnt; edge[cnt].to=v;}
inline void InsertEdge(int u,int v) {AddEdge(u,v); AddEdge(v,u);}
namespace SegmentTree
{
    struct SegmentTreeNode{int l,r,size,tag,sum;}tree[MAXN<<2];
    #define ls now<<1
    #define rs now<<1|1
    inline void Update(int now) {tree[now].sum=tree[ls].sum+tree[rs].sum;}
    inline void PushDown(int now)
    {
        if (tree[now].tag==-1 || tree[now].l==tree[now].r) return;
        tree[ls].sum=tree[ls].size*tree[now].tag; tree[ls].tag=tree[now].tag;
        tree[rs].sum=tree[rs].size*tree[now].tag; tree[rs].tag=tree[now].tag;
        tree[now].tag=-1;
    }
    inline void BuildTree(int now,int l,int r)
    {
        tree[now].l=l; tree[now].r=r; tree[now].size=r-l+1;
        tree[now].tag = -1;
        tree[now].sum = 0;
        if (l==r) return;
        int mid=(l+r)>>1;
        BuildTree(ls,l,mid); BuildTree(rs,mid+1,r);
        Update(now);
    }
    inline void Change(int now,int L,int R,int D) 
    {
        int l=tree[now].l,r=tree[now].r;
        if (L<=l && R>=r) {tree[now].tag=D; tree[now].sum=tree[now].size*D; return;}
        PushDown(now);
        int mid=(l+r)>>1;
        if (L<=mid) Change(ls,L,R,D);
        if (R>mid) Change(rs,L,R,D);
        Update(now);
    }
    inline int Query(int now,int pos){
    	int l=tree[now].l,r=tree[now].r;
    	if (l==r){
    		return tree[now].sum;
		}
		PushDown(now);
		int mid=(l+r)>>1;
		if (pos<=mid) return Query(ls,pos);
		else return Query(rs,pos);
	}
}
namespace TreePartition
{
    int fa[MAXN],size[MAXN],son[MAXN],deep[MAXN],pl[MAXN],dfn,pr[MAXN],pre[MAXN],top[MAXN];
    inline void DFS_1(int now)
    {
        size[now]=1;
        for (int i=head[now]; i; i=edge[i].next)
            if (edge[i].to!=fa[now])
                {
                    deep[edge[i].to]=deep[now]+1;
                    fa[edge[i].to]=now;
                    DFS_1(edge[i].to);
                    size[now]+=size[edge[i].to];
                    if (size[son[now]]<size[edge[i].to]) son[now]=edge[i].to;
                }
    }
    inline void DFS_2(int now,int chain)
    {
        top[now]=chain; pl[now]=++dfn; pre[dfn]=now;
        if (son[now]) DFS_2(son[now],chain);
        for (int i=head[now]; i; i=edge[i].next)
            if (edge[i].to!=fa[now] && edge[i].to!=son[now])
                DFS_2(edge[i].to,edge[i].to);
        pr[now]=dfn;
    }
    inline void Change(int x,int y,int D)
    {
        while (top[x]!=top[y])
            {
                if (deep[top[x]]<deep[top[y]]) swap(x,y);
                SegmentTree::Change(1,pl[top[x]],pl[x],D);
                x=fa[top[x]];
            }
        if (deep[x]>deep[y]) swap(x,y);
        SegmentTree::Change(1,pl[x],pl[y],D);
    }
    inline void Query(int x) {printf("%d\n",SegmentTree::Query(1,pl[x]));}
    inline void Modify(int x,int D){
    	SegmentTree::Change(1,pl[x],pr[x],D);
	}
//    inline void Query(int x) {printf("%lld\n",SegmentTree::Query(1,pl[x],pr[x]));}
}
int main()
{
    N=read();
    for (int x,y,i=1; i<=N-1; i++) x=read(),y=read(),InsertEdge(x,y);
    TreePartition::DFS_1(1); TreePartition::DFS_2(1,1); 
    SegmentTree::BuildTree(1,1,N);
    Q=read();
    while (Q--){
    	int c=read(),v=read();
    	if (c==1){
    		TreePartition::Modify(v,1);
		} else if (c==2){
			TreePartition::Change(1,v,0);
		} else {
			TreePartition::Query(v);
		}
	}
    return 0;
}