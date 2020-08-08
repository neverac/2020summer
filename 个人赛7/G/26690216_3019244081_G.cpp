#include<bits/stdc++.h>
#include<queue>
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 
*/
#define ll long long
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;

char mp[1100][1100];
bool vis[1100][1100];
int n,m;
struct node{
	int x,y,d;
    bool operator < (const node &e)const{
        return d > e.d;
    }
};
priority_queue <node> pq;
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};
int bfs(){
	while(!pq.empty()){
		node a=pq.top();
		pq.pop();
		if(mp[a.x][a.y]=='2') return a.d;
		for(int i=0;i<4;i++){
			int x=a.x+dx[i];
			int y=a.y+dy[i];
			if(x>=1 && x<=n && y>=1 && y<=m && !vis[x][y]){
				pq.push({x,y,a.d+1});
				vis[x][y]=true;
			}
		}
	}
	return 1000001;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=m;j++){
			scanf("%c",&mp[i][j]);
			if(mp[i][j]=='1'){
				vis[i][j]=true;
				pq.push({i,j,1});
			}
		}
	}
	printf("%d",bfs());
	return 0;
}