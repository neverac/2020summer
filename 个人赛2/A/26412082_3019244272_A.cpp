#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 10;
int n, m;
int st[maxn][maxn];
bool vis[maxn][maxn];
int ans = 0, tot = 0;;
struct P{
	int x, y;
	P(int x = 0, int y = 0): x(x), y(y){}
};
bool judge(int x, int y){
	return 0 <= x && x <= n && 0 <= y && y <= m && !vis[x][y]; 
}
queue<P> q;
void bfs(int x, int y){
	int sum = 0;
	vis[x][y] = 1;
	q.push(P(x, y));
	while(!q.empty()){
		P p = q.front(); q.pop();
		if(!(st[p.x][p.y] & 1) && judge(p.x, p.y - 1)){
			q.push(P(p.x, p.y - 1));
			vis[p.x][p.y - 1] = true;
		}
		if(!(st[p.x][p.y] & 2) && judge(p.x - 1, p.y)){
			q.push(P(p.x - 1, p.y));
			vis[p.x - 1][p.y] = true;
		}
		if(!(st[p.x][p.y] & 4) && judge(p.x, p.y + 1)){
			q.push(P(p.x, p.y + 1));
			vis[p.x][p.y + 1] = true;
		}
		if(!(st[p.x][p.y] & 8) && judge(p.x + 1, p.y)){
			q.push(P(p.x + 1, p.y));
			vis[p.x + 1][p.y] = true;
		}
		sum++;
	}
	ans = max(ans, sum);
	tot++;
}
int main(){	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> st[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!vis[i][j]) bfs(i, j);
		}
	}
	cout << tot << endl << ans << endl;
	return 0;
}