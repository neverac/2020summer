#include<bits/stdc++.h>
using namespace std;
#define MAXN 20010
const int INF = 0x7fffffff;
int N,M,l[MAXN],r[MAXN],w[MAXN];

struct EdgeNode{
    int next,to,cap,cost;
}edge[5000010];
int head[MAXN],cnt=1;
inline void AddEdge(int u,int v,int w,int c) {cnt++; edge[cnt].next=head[u]; head[u]=cnt; edge[cnt].to=v; edge[cnt].cap=w; edge[cnt].cost=c;}
inline void insert(int u,int v,int w,int c) {AddEdge(u,v,w,c); AddEdge(v,u,0,-c);}
 
int Cost,S,T,dis[MAXN],mark[MAXN];
queue<int>q;
inline bool spfa()
{
    for (int i=S; i<=T; i++) dis[i]=-INF,mark[i]=0;
    queue<int>q;
    q.push(S); dis[S]=0; mark[S]=1;
    while (!q.empty()) {
        int now=q.front(); q.pop(); mark[now]=0;
        for (int i=head[now]; i; i=edge[i].next)
            if (edge[i].cap && dis[edge[i].to]<dis[now]+edge[i].cost) {
                    dis[edge[i].to]=dis[now]+edge[i].cost;
                    if (!mark[edge[i].to]) q.push(edge[i].to),mark[edge[i].to]=1;
            }
    }
    return dis[T]!=-INF;
}
 
inline int dfs(int loc,int low)
{
    mark[loc]=1;
    if (loc==T) return low;
    int used=0,w;
    for (int i=head[loc]; i; i=edge[i].next)
        if (edge[i].cap && !mark[edge[i].to] && dis[edge[i].to]==dis[loc]+edge[i].cost) {
            w=dfs(edge[i].to,min(edge[i].cap,low-used));
            edge[i].cap-=w; edge[i^1].cap+=w; used+=w; Cost+=w*edge[i].cost;
            if (low==used) return used;
        }
    return used;
}
 
inline int zkw()
{
    int re=0;
    while (spfa()) {
        mark[T]=1;
        while (mark[T]) {
            for (int i=S; i<=T; i++) mark[i]=0;
            re+=dfs(S,INF);
        }
    }
    return re;
}
int main(){
	scanf("%d%d",&N,&M);
	for (int i=1; i<=N; i++){
		scanf("%d%d%d",&l[i],&r[i],&w[i]);
	}
	S = 0,T = 2*N+2;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			if (i==j) continue;
			if (r[i]<=l[j]){
				insert(i+N,j,1,0);
//				printf("%d  %d\n",i,j); 
			} 
		}
		insert(S,i,1,0);
		insert(i+N,T-1,1,0);
		insert(i,i+N,1,w[i]);
	}
	insert(T-1,T,M,0);
	int flow = zkw();
	printf("%d\n",Cost);
	return 0;
}