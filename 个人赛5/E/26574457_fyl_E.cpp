#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const int maxn = 200010;

struct edge{int to,dis,next;}e[maxn*2];
int tot,head[maxn];
void add(int u,int v,int z){
	e[++tot].to=v;
	e[tot].next=head[u];
	e[tot].dis=z;
	head[u]=tot;
}
int dis[maxn];
void dfs(int u,int fa){
	for(int i=head[u];i;i=e[i].next){
		int to=e[i].to;
		if(to==fa) continue;
		dis[to]=dis[u]^e[i].dis;
		dfs(to,u);
	}
}

bool cmp(int a,int b){
	for(int i=30;~i;i--){
		if(((1<<i)&a)!=((1<<i)&b))
			return ((1<<i)&a)<((1<<i)&b);
	}
	return 0;
}
ll ans=0;
int ch[30*maxn][2],val[30*maxn],sz;  
void insert(int num){  
    int u=0;  
    for(int i=29;i>=0;i--){  
        int c=((num>>i)&1);
        if(!ch[u][c]){  
            ch[u][c]=++sz;  
        }  
        u=ch[u][c]; 
        val[u]++;  
    }  
}  
void remove(int num)
{
	int u=0;
	for(int i=29;i>=0;i--)
	{
		int c=((num>>i)&1);
		int pre = u;
		u = ch[u][c];
		if(--val[u]==0) ch[pre][c]=0;
	}
}
  
int query(int num){  
    int p=0,v=0;
    for(int i=29;i>=0;i--)
    {
    	int c=((num>>i)&1);
    	if(ch[p][c])p=ch[p][c];
    	else 
    	{
    		p=ch[p][c^1];
    		v+=(1<<i);
    	}
    }
    return v; 
}  
void get(int l,int r,int op){
	if(op==-1) return;
	int mid=-1;
	for(int i=l;i<=r;i++){
		if(dis[i]&(1<<op)){
			mid=i;break;
		}
	}
	if((mid==l)||(mid==-1)){
		get(l,r,op-1);
		return;
	}
	int now=0x7f7f7f7f;
	for(int i=l;i<mid;i++) insert(dis[i]);
	for(int i=mid;i<=r;i++)
		now=min(now,query(dis[i]));
	ans+=now;
	sz=0;
	for(int i=l;i<mid;i++) remove(dis[i]);
	get(l,mid-1,op-1);
	get(mid,r,op-1);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&dis[i]);
	sort(dis+1,dis+n+1,cmp);
	//puts("ok");
	get(1,n,30);
	printf("%lld\n",ans);
	return 0;
}	