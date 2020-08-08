#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 100010;
struct Link{
	int to,next;
}link[SIZEN << 1];
int head[SIZEN],tot = 0;
void add(int from,int to){
  	link[++tot].to = to;
  	link[tot].next = head[from];
  	head[from] = tot;
}
int N ;
int sz[SIZEN];
int son[SIZEN];
void dfs(int x,int fa){
	sz[x] = 1;
	for(int i = head[x];i;i=link[i].next){
		if(link[i].to == fa)continue;
		dfs(link[i].to,x);
		sz[x] += sz[link[i].to];
		son[x] = max(son[x],sz[link[i].to]);
	}
	son[x] = max(son[x],N-sz[x]);
}
int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		int x;scanf("%d",&x);
		if(i!=1)add(x,i);
	}
	dfs(1,1);
	int sum = 0;
	int lim = N/2;
	if(N % 2 == 0)lim --;
	for(int i = 1;i <= N;i++){
		if(son[i] <= lim)sum++;
	}
	printf("%d\n",sum);
	for(int i = 1;i <= N;i++){
		if(son[i] <= lim)printf("%d ",i);
	}
	return 0;
}