#include <bits/stdc++.h>
using namespace std;
int a[1100][1100];
int vis[1100][1100];
int n,m;
struct node{
	int x,y,t;
};
queue <node> q;
const int dx[4]={-1,0,0,1};
const int dy[4]={0,1,-1,0};
void bfs(){
	while (!q.empty()){
		node now=q.front();
		q.pop();
		for (int i=0;i<4;i++){
			if (now.x+dx[i]<=0||now.x+dx[i]>n) continue;
			if (now.y+dy[i]<=0||now.y+dy[i]>m) continue;
			if (!vis[now.x+dx[i]][now.y+dy[i]]){
				if (a[now.x+dx[i]][now.y+dy[i]]==2){
					cout<<now.t+1<<endl;
					return;
				}else {
					q.push({now.x+dx[i],now.y+dy[i],now.t+1});
					vis[now.x+dx[i]][now.y+dy[i]]=1;
				}
			}
		}
	}	
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		string s;
		cin>>s;
		for (int j=0;j<m;j++){
			if (s[j]=='1') a[i][j]=1,q.push({i,j,1}),vis[i][j]=1;
			if (s[j]=='2') a[i][j]=2;
		} 
	}
	bfs();
	return 0;
}

