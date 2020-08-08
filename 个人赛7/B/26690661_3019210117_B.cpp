#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX_N=100001,MAX_M=200001;
int head[MAX_N]={0},next1[MAX_N]={0},V[MAX_N]={0},tot=0,rt=0;
int dfn[MAX_N],low[MAX_N],stap[MAX_N],belong[MAX_N];
int n,m,bcnt,dindex=0,stop=0;
bool instack[MAX_N];
void tarjan(int v){
	int u;
	dfn[v]=low[v]=++dindex;
	instack[v]=true;
	stap[++stop]=v;
	for (int i=head[v];i;i=next1[i]){
		u=V[i];
		if(!dfn[u]){
			tarjan(u);
			if(low[u]<low[v]){
				low[v]=low[u];
            }
		}else if(instack[u]&&dfn[u]<low[v]){
			low[v]=dfn[u];
        }
	}
	if(dfn[v]==low[v]){
		bcnt++;
		do{
			u=stap[stop--];
			instack[u]=false;
			belong[u]=bcnt;
		}while(u!=v);
	}
}
void add(int x,int y){
	tot++;
	next1[tot]=head[x];
	V[tot]=y;
    head[x]=tot;
}
bool vis[MAX_N],flag=1;
void dfs(int rt){
	vis[rt]=1;
	for(int i=head[rt];i;i=next1[i]){
		int to=V[i];
		if(vis[to]){
            continue;
        }
		dfs(to);
	}
}
int num[MAX_N]={0};
int main(){
    //freopen("in.txt","r",stdin);
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a=0,b=0;
        scanf("%d%d",&a,&b);
		add(a,b);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			rt=i;
		}
	}
	memset(vis,0,sizeof(vis));
    dfs(rt);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
            flag=0;
        }
	}
	if(!flag){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
            tarjan(i);
        }
	}
	for(int i=1;i<=n;i++){
		num[belong[i]]++;
	}
	printf("%d",num[belong[rt]]);
	return 0;
} 