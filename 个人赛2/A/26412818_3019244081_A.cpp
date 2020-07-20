#include<bits/stdc++.h>
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
bool vis[100][100];
int  mp[100][100];
int n,m;
int dfs(int x,int y){
	vis[x][y]=true;
	int ret1=1;
	//printf("???%d???",mp[x][y]);
	//printf("wow");
	//×óÎ÷1
	if(mp[x][y]%2==0  && y-1>0 && !vis[x][y-1]) ret1+=dfs(x,y-1);
	//ÉÏ±±2
	mp[x][y]/=2;
	if(mp[x][y]%2==0  && x-1>0 && !vis[x-1][y]) ret1+=dfs(x-1,y);
	//ÓÒ¶«4
	mp[x][y]/=2;
	if(mp[x][y]%2==0  && y+1<=n && !vis[x][y+1]) ret1+=dfs(x,y+1);
	//ÏÂÄÏ8
	mp[x][y]/=2;
	if(mp[x][y]==0  && x+1<=m && !vis[x+1][y]) ret1+=dfs(x+1,y);
	//printf("ret:%d   ",ret1);
	return ret1;
}
int main(){
	scanf("%d%d",&m,&n);
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mp[i][j]);	
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",mp[i][j]);	
		}
	}*/
	int cnt=0,mx=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j]){
				//printf("???");
				mx=max(mx,dfs(i,j));
				cnt++;
			}
		}
	}
	printf("%d\n%d",cnt,mx);
	return 0;
}