#include <iostream>
using namespace std;
const int maxn = 100000 + 10, maxm = 200000 + 10;
struct Edge{
	int v, next;
	Edge(){}
	Edge(int v, int next): v(v), next(next){}
}e[maxm * 2];
int fir[maxn], ecnt;
inline void add(int u, int v){
	e[++ecnt] = Edge(v, fir[u]); fir[u] = ecnt;
}
int n, m, bcnt;
int dfn[maxn], low[maxn], touma;
int sta[maxn], top;
bool ins[maxn];
int bel[maxn], siz[maxn];
void dfs(int u){
	dfn[u] = low[u] = ++touma;
	sta[++top] = u; ins[u] = true;
	for(int i = fir[u]; i; i = e[i].next){
		int v = e[i].v;
		if(dfn[v]){
			if(ins[v]) low[u] = min(low[u], dfn[v]);
		}
		else{
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if(low[u] == dfn[u]){
		int x;
		bcnt++;
		do{
			x = sta[top--];
			ins[x] = false;
			siz[bcnt]++;
			bel[x] = bcnt;
		}while(x != u);
	}
}
int ind[maxn];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) dfs(i);
	}
	for(int u = 1; u <= n; u++){
		for(int i = fir[u]; i; i = e[i].next){
			if(bel[u] != bel[e[i].v]) ind[bel[e[i].v]]++;
		}
	}
	int ans, num = 0;
	for(int i = 1; i <= bcnt; i++){
		if(ind[i] == 0){
			ans = siz[i];
			num++;
		}
	}
	if(num == 1) cout << ans << endl;
	else cout << 0 << endl;
	return 0;
}