#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
struct Point{
	int x, y;
	int id;
	Point(){}
	friend bool operator < (const Point &a, const Point &b){
		if(a.x != b.x) return a.x < b.x;
		else return a.y < b.y;
	}
}p[maxn];
vector<int> g[maxn];
int ans[maxn];
bool vis[10];
int Judge(int id){
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < g[id].size(); i++){
		vis[ans[g[id][i]]] = true;
	}
	for(int i = 1; i <= 4; i++){
		if(!vis[i]) return i;
	}
	return -1;
}
void force(int id, int s, int t){
	ans[id] = s;
	for(int i = 0; i < g[id].size(); i++){
		if(ans[g[id][i]] == s){
			force(g[id][i], t, s);
		}
	}
}
void work(int id){
	int t = Judge(id);
	if(t != -1){
		ans[id] = t;
		return;
	}
	for(int i = 0; i < g[id].size(); i++){
		if(!ans[g[id][i]]) continue;
		for(int j = 1; j <= 4; j++){
			force(g[id][i], j, ans[g[id][i]]);
			t = Judge(id);
			if(t != -1){
				ans[id] = t;
				return;
			}
		}
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++) work(p[i].id);
	for(int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
	return 0;
}