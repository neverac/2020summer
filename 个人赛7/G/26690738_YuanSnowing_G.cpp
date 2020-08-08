#include <bits/stdc++.h>
using namespace std;
char ch;
int n,m,ma[1024][1024],ans,mx[]={1,0,-1,0},my[]={0,1,0,-1},vis[1024][1024];
struct node{
	int x,y,st;
};
queue<node> q;
void bfs(){
	int x,y,a;
	node tmp;
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		x = tmp.x;
		y = tmp.y;
		for(int i=0;i<4;++i){
			a = ma[x+mx[i]][y+my[i]];
			if(a == 0) continue;
			if(a == 2) {
				ans = tmp.st+1;
				return;
			}
			if(a == 3 && !vis[x+mx[i]][y+my[i]]){
				vis[x+mx[i]][y+my[i]] = 1;
				q.push({x+mx[i],y+my[i],tmp.st+1});
			}
		}
	}
}
int main(){
	cin >> n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin >> ch;
			ma[i][j] = ch-'0';
			if(ma[i][j]==1) {
				q.push({i,j,1});
				vis[i][j] = 1;
			}
			if(ma[i][j]==0) ma[i][j] = 3;
		}
	}
	bfs();
	cout << ans << endl;
	return 0;
}
