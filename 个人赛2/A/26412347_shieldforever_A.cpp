#include<bits/stdc++.h>
using namespace std;
#define N 55
int g[N][N][4];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;

void work(int i, int j, int p){
    if(p >= 8){
        p -= 8;
        g[i][j][1] = 1;
    }
    if(p >= 4){
        p -= 4;
        g[i][j][0] = 1;
    }
    if(p >= 2){
        p -= 2;
        g[i][j][3] = 1;
    }
    if(p >= 1){
        g[i][j][2] = 1;
    }
    return ;
}

void init(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int p;
            cin>>p;
            work(i, j, p);
        }
    }
    return ;
}
int sum, ans;
int vis[N][N];

void dfs(int x, int y){
    vis[x][y] = 1;
    sum++;
    for(int i = 0; i < 4; i++){
        if(x + dx[i] <= 0 || y + dy[i] <= 0 || x + dx[i] > n || y + dy[i] > m) continue;
        if(g[x][y][i] == 0 && !vis[x + dx[i]][y + dy[i]])dfs(x + dx[i], y + dy[i]);
    }
    return ;
}

void solve(){
    ans = 0;
    int k = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j]){
                sum = 0;
                ++k;
                dfs(i, j);
                if(sum > ans) ans = sum;
            }
        }
    }
    cout<<k<<endl;
    cout<<ans<<endl;
    return ;
}

int main(){
    init();
    solve();
    return 0;
}