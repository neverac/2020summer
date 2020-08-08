#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
struct Edge{
	int v, next;
	Edge(){}
	Edge(int v, int next): v(v), next(next){}
}e[maxn];
int fir[maxn], ecnt;
inline void add(int u, int v){
	e[++ecnt] = Edge(v, fir[u]); fir[u] = ecnt;
}
int n, root;
int siz[maxn];
bool mark[maxn];
void dfs(int u){
	siz[u] = 1;
	for(int i = fir[u]; i; i = e[i].next){
		int v = e[i].v;
		dfs(v);
		siz[u] += siz[v];
		if(siz[v] >= n - siz[v]) mark[u] = true;
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int fa;
		cin >> fa;
		if(fa == 0) root = i;
		else add(fa, i);
	}
	dfs(root);
	int k = 0;
	for(int i = 1; i <= n; i++){
		if(siz[i] > n - siz[i] && !mark[i]) k++;
	}
	cout << k << endl;
	for(int i = 1; i <= n; i++){
		if(siz[i] > n - siz[i] && !mark[i]) cout << i << endl;
	}
	return 0;
}