#include<iostream>
#include<cstdio>
#include<algorithm>
int wall[55][55];
int vis[55][55];
int room, biggest,now;
using namespace std;
void DFS(int x,int y){
    if(vis[x][y]){
        return;
    }
    now++;
    vis[x][y]=1;
    //1111共4面墙 0001西 0010北 0100东 1000南
    if((wall[x][y]&1)==0){
        DFS(x,y-1);
    }
    if((wall[x][y]&2)==0){
        DFS(x-1,y);
    }
    if((wall[x][y]&4)==0){
        DFS(x,y+1);
    }
    if((wall[x][y]&8)==0){
        DFS(x+1,y);
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) {
            scanf("%d",&wall[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                now=0;
                room++;
                DFS(i,j);
                biggest = max(biggest,now);
            }
        }
    }
    cout<<room<<endl;
    cout<<biggest<<endl;
    return 0;
}