#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson o<<1,l,Mid
#define rson o<<1|1,Mid+1,r
#define MID Mid=(l+r)>>1
#define maxn 1000010 
inline int read(){
	int ret=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-ff;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*ff;
}
int n,m,Root,p;
struct Edge{
	int u,v,next;
}E[maxn<<1];
int head[maxn],ecnt;
void addedge(int u,int v){
	E[++ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}
void Addedge(int aa,int bb){
	addedge(aa,bb);
	addedge(bb,aa);
}
int dep[maxn],siz[maxn],fa[maxn],hv[maxn],top[maxn];
void dfs1(int x,int fx){
	dep[x]=dep[fx]+1;
	siz[x]=1;
	fa[x]=fx;
	int maxx=0;
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		if(v==fx) continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>maxx){
			maxx=siz[v];
			hv[x]=v;
		}
	}
}
int dfn[maxn],cnt=0,wt[maxn],w[maxn];
int tr[maxn];
void dfs2(int x,int topp){
	top[x]=topp;
	dfn[x]=++cnt;
	wt[cnt]=w[x];
	if(hv[x]==0) return ;
	dfs2(hv[x],topp);
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		if(v==fa[x]||v==hv[x]) continue;
		dfs2(v,v);
	}
}
int lazy[maxn];

void pushdown(int o,int l,int r){
	if(lazy[o]!=-1){
		if(l==r){
			tr[o]=lazy[o];
			lazy[o]=-1;
			return ;
		}
		lazy[o<<1]=lazy[o];
		lazy[o<<1|1]=lazy[o];
		lazy[o]=-1;
	}
}

int query(int o,int l,int r,int x){
	if(l==r){
		if(lazy[o]!=-1) return lazy[o];
		else return tr[o];
	}
	pushdown(o,l,r);
	int MID,ret=0;
	if(x<=Mid) return query(lson,x);
	else return query(rson,x);
}
void update(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		lazy[o]=val;
		return ;
	}
	pushdown(o,l,r);
	int MID;
	if(ql<=Mid) update(lson,ql,qr,val);
	if(qr>Mid) update(rson,ql,qr,val);
}

void Update2(int x,int val){
	update(1,1,n,dfn[x],dfn[x]+siz[x]-1,val);
}
int Query2(int x){
	return query(1,1,n,dfn[x]);
}
void Update1(int x,int y,int val){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,1,n,dfn[top[x]],dfn[x],val);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	update(1,1,n,dfn[x],dfn[y],val);
}

int main(){
	memset(lazy,-1,sizeof(lazy));
	
	n=read();
	Root=1;
	for(int i=1;i<n;++i){
		int aa,bb;
		scanf("%d%d",&aa,&bb);
		Addedge(aa,bb);
	}
	dfs1(Root,0);//puts("wqwq");
	dfs2(Root,Root);
//	puts("qwq");
//	build(1,1,n);
	m=read();
	while(m--){
	//	puts("qwqwq");
		int op=read();
		int x=read();
		if(op==1){
			Update2(x,1);
		}
		if(op==2){
			Update1(1,x,0);
		}
		if(op==3){
			printf("%d\n",Query2(x));
		}
	}
}