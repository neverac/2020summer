#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int m,n;    //行列数
int mm[100][100];    
int maxr=1;    //最大房间连通数
bool vis[100][100];   
int room=0;    //某连通分量的节点个数；
bool dfs(int x,int y){
    if(x==0||y==0||x>m||y>n) return 0;
    if(vis[x][y]) return 0;    //访问过就不再访问
    room++;  
    if(room>=maxr) 
    maxr=room;
    if(mm[x][y]-8<0){    //一个结点的四个方向，哪个方向没有墙就向哪里搜索
        vis[x][y]=1;
         dfs(x+1,y);
    }
    else
        mm[x][y]-=8;
     if(mm[x][y]-4<0){
        vis[x][y]=1;
         dfs(x,y+1);
    }
    else
        mm[x][y]-=4;
     if(mm[x][y]-2<0){
        vis[x][y]=1;
         dfs(x-1,y);
    }
    else
        mm[x][y]-=2;
     if(mm[x][y]-1<0){
        vis[x][y]=true;
         dfs(x,y-1);
    }
    else
        mm[x][y]-=1;
    return true;
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&mm[i][j]);
            }
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            room=0;    //初始化房间数（结点数）
            if(dfs(i,j))    //判断当前结点是否属于联通分量。
                cnt++;
        }
    }
    printf("%d\n",cnt);
    printf("%d\n",maxr);
   
    return 0;
}