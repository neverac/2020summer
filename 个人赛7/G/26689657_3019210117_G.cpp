#include <iostream>
#include <queue>
using namespace std;
int tag[1005][1005],dis[1005][1005],ans=1000005,dxy[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[1005][1005];
char x;
struct search_node{
    int x,y,d;
    search_node(int x1=0,int y1=0,int d1=0){
        x=x1;
        y=y1;
        d=d1;
    }
    bool operator<(const search_node &b)const{
        return d>b.d;
    }
}tem;
priority_queue<search_node>searchque;
int bfs(){
    while(!searchque.empty()){
        tem=searchque.top();
        dis[tem.x][tem.y]=tem.d;
        searchque.pop();
        if(tag[tem.x][tem.y]==1){
            return tem.d;
        }
        for(int i=0;i<4;i++){
            if(!vis[tem.x+dxy[i][0]][tem.y+dxy[i][1]]){
                vis[tem.x+dxy[i][0]][tem.y+dxy[i][1]]=1;
                searchque.push(search_node(tem.x+dxy[i][0],tem.y+dxy[i][1],tem.d+1));
            }
        }
    }
    return -1;
}
int main(){
    //freopen("in.txt","r",stdin);
    while(!searchque.empty()){
        searchque.pop();
    }
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=0;
        }
    }
    for(int i=0;i<=n+1;i++){
        vis[i][0]=vis[i][m+1]=1;
    }
    for(int i=0;i<=m+1;i++){
        vis[0][i]=vis[n+1][i]=1;
    }
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=m;j++){
            scanf("%c",&x);
            tag[i][j]=x-'0';
            if(tag[i][j]==2){
                searchque.push(search_node(i,j,1));
                vis[i][j]=1;
            }
        }
    }
    printf("%d\n",bfs());
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%2d",dis[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
