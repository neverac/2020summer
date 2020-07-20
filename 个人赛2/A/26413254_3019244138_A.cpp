#include<iostream>
using namespace std;
int m,n;  
int ma[100][100]; 
int maxnum=1;    
int visited[100][100];
int room=0;    
int dfs(int x,int y){
    if(x==0||y==0||x>m||y>n) return 0;
    if(visited[x][y]) return 0;    
    room++;    
    if(room>=maxnum) maxnum=room;
    if(ma[x][y]-8<0){    
        visited[x][y]=true;
         dfs(x+1,y);
    }
    else
        ma[x][y]-=8;

     if(ma[x][y]-4<0){
        visited[x][y]=true;
         dfs(x,y+1);
    }
    else
        ma[x][y]-=4;

     if(ma[x][y]-2<0){
        visited[x][y]=true;
         dfs(x-1,y);
    }
    else
        ma[x][y]-=2;

     if(ma[x][y]-1<0){
        visited[x][y]=true;
         dfs(x,y-1);
    }
    else
        ma[x][y]-=1;
    return 1;
}
int main(){
    cin >> m >> n ;
    for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&ma[i][j]);
            }
    }
    int num=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            room=0;    
            if(dfs(i,j))    
                num++;
        }
    }
    cout<<num<<endl;
    cout<<maxnum<<endl;
    return 0;
}
