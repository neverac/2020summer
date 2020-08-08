#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
#define maxn 400010
int id[maxn<<2],va[maxn<<2],uu[maxn],vv[maxn],ww[maxn];
int n;struct data{int next,to,w;}edge[maxn<<1];int head[maxn],cnt;
void add(int u,int v,int w){cnt++;edge[cnt].w=w;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;}
void insert(int u,int v,int w){add(u,v,w); add(v,u,w);}
//--------------------------------------------------------------------------------------
int deep[maxn],fa[maxn],son[maxn],size[maxn],pl[maxn],sz,pr[maxn],top[maxn],pre[maxn];
void dfs_1(int now)
{
    size[now]=1;
    for (int i=head[now]; i; i=edge[i].next)
        if (edge[i].to!=fa[now])
            {
                fa[edge[i].to]=now;
                deep[edge[i].to]=deep[now]+1;
                dfs_1(edge[i].to);
                if (size[son[now]]<size[edge[i].to]) son[now]=edge[i].to;
                size[now]+=size[edge[i].to];
            }
}
void dfs_2(int now,int chain)
{
    pl[now]=++sz; pre[sz]=now; top[now]=chain;
    if (son[now]) dfs_2(son[now],chain);
    for (int i=head[now]; i; i=edge[i].next)
        if (edge[i].to!=son[now] && edge[i].to!=fa[now])
            dfs_2(edge[i].to,edge[i].to);
    pr[now]=sz;
}
//--------------------------------------------------------------------------------------
int tree[maxn<<2],delc[maxn<<2],dela[maxn<<2];
inline void update(int now){tree[now]=max(tree[now<<1],tree[now<<1|1]);}
inline void pushdown(int now)
{
    if (delc[now]!=-1)
        {
            int cc=delc[now]; delc[now]=-1;
            delc[now<<1]=cc; dela[now<<1]=0; tree[now<<1]=cc;
            delc[now<<1|1]=cc; dela[now<<1|1]=0; tree[now<<1|1]=cc;
        }
    if (dela[now])
        {
            int aa=dela[now]; dela[now]=0;
            dela[now<<1]+=aa; tree[now<<1]+=aa;
            dela[now<<1|1]+=aa; tree[now<<1|1]+=aa;
        }
}
void build(int now,int l,int r)
{
    delc[now]=-1; dela[now]=0;
    if (l==r) {tree[now]=va[l];return;}
    int mid=(l+r)>>1;
    build(now<<1,l,mid); build(now<<1|1,mid+1,r);
    update(now);
}
void point_change(int now,int l,int r,int loc,int val)
{
    if (l==r) {tree[now]=val;return;}
    int mid=(l+r)>>1;pushdown(now);
    if (loc<=mid) point_change(now<<1,l,mid,loc,val);
    else point_change(now<<1|1,mid+1,r,loc,val);  
    update(now);
}
int segment_ask(int now,int l,int r,int L,int R)
{
    if (L<=l && R>=r) return tree[now];
    int mid=(l+r)>>1; int ans=0;pushdown(now);
    if (L<=mid) ans=max(segment_ask(now<<1,l,mid,L,R),ans);
    if (R>mid) ans=max(ans,segment_ask(now<<1|1,mid+1,r,L,R));
    return ans;
}
//--------------------------------------------------------------------------------------
void Change(int x,int val)
{
    point_change(1,1,n,pl[id[x]],val);
}
void Max(int x,int y)
{
    int ans=0;
    while (top[x]!=top[y])
        {
            if (deep[top[x]]<deep[top[y]]) swap(x,y);
            ans=max(ans,segment_ask(1,1,n,pl[top[x]],pl[x]));
            x=fa[top[x]];
        }
    if (deep[x]>deep[y]) swap(x,y);
    if (x!=y) ans=max(ans,segment_ask(1,1,n,pl[x]+1,pl[y]));
    printf("%d\n",ans);
}
//--------------------------------------------------------------------------------------
void work(){
	n=read();
    for (int i=1; i<=n-1; i++)
        uu[i]=read(),vv[i]=read(),ww[i]=read(),insert(uu[i],vv[i],ww[i]);
    dfs_1(1); dfs_2(1,1);
    for (int i=1; i<=n-1; i++)
        if (deep[uu[i]]<deep[vv[i]]) id[i]=vv[i]; else id[i]=uu[i];
    for (int i=1; i<=n-1; i++) va[pl[id[i]]]=ww[i];//边权下放至点，记录所下放的点的id
    build(1,1,n);
    while (true)
        {
            char opt[10]; scanf("%s",opt+1);if(opt[1]=='D')break;
            int u=read(),v=read(),w;
            switch (opt[1]){
                case 'Q': Max(u,v);break;
                case 'C': Change(u,v);break;
            }
        }	
}
int main()
{
	int cas = read();
	while (cas--){
		work();
		for (int i=1; i<=n; i++) head[i]=0;
		for (int i=1; i<=n; i++){
			id[i] =0;
			fa[i] = 0;
			son[i] = 0;
		} 
		cnt=1;
		sz = 0;
	}
    return 0;
}

/*
2
3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE
3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE
*/