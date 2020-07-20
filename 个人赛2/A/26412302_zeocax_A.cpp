#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
int N, M;
int m[51][51];
bool vis[51][51];
int dfs(int x, int y){
    vis[x][y] = true;
    int ret = 1;
    if(m[x][y] == 0){
        if(!vis[x - 1][y] && x - 1 >= 1)ret += dfs(x - 1, y);
        if(!vis[x + 1][y] && x + 1 <= N)ret += dfs(x + 1, y);
        if(!vis[x][y - 1] && y - 1 >= 1)ret += dfs(x, y - 1);
        if(!vis[x][y + 1] && y + 1 <= M)ret += dfs(x, y + 1);
    }
    else if(m[x][y] == 1){
        if(!vis[x - 1][y] && x - 1 >= 1)ret += dfs(x - 1, y);
        if(!vis[x + 1][y] && x + 1 <= N)ret += dfs(x + 1, y);
        if(!vis[x][y + 1] && y + 1 <= M)ret += dfs(x, y + 1);
    }
    else if(m[x][y] == 2){
        if(!vis[x + 1][y] && x + 1 <= N)ret += dfs(x + 1, y);
        if(!vis[x][y - 1] && y - 1 >= 1)ret += dfs(x, y - 1);
        if(!vis[x][y + 1] && y + 1 <= M)ret += dfs(x, y + 1);
    }
    else if(m[x][y] == 4){
        if(!vis[x - 1][y] && x - 1 >= 1)ret += dfs(x - 1, y);
        if(!vis[x + 1][y] && x + 1 <= N)ret += dfs(x + 1, y);
        if(!vis[x][y - 1] && y - 1 >= 1)ret += dfs(x, y - 1);
    }
    else if(m[x][y] == 8){
        if(!vis[x - 1][y] && x - 1 >= 1)ret += dfs(x - 1, y);
        if(!vis[x][y - 1] && y - 1 >= 1)ret += dfs(x, y - 1);
        if(!vis[x][y + 1] && y + 1 <= M)ret += dfs(x, y + 1);
    }
    else if(m[x][y] == 3){
        if(!vis[x + 1][y] && x + 1 <= N)ret += dfs(x + 1, y);
        if(!vis[x][y + 1] && y + 1 <= M)ret += dfs(x, y + 1);
    }
    else if(m[x][y] == 5){
        if(!vis[x - 1][y] && x - 1 >= 1)ret += dfs(x - 1, y);
        if(!vis[x + 1][y] && x + 1 <= N)ret += dfs(x + 1, y);
    }
    else if(m[x][y] == 9){
        if(!vis[x - 1][y] && x - 1 >= 1)ret += dfs(x - 1, y);
        if(!vis[x][y + 1] && y + 1 <= M)ret += dfs(x, y + 1);
    }
    else if(m[x][y] == 6){
        if(!vis[x + 1][y] && x + 1 <= N)ret += dfs(x + 1, y);
        if(!vis[x][y - 1] && y - 1 >= 1)ret += dfs(x, y - 1);
    }
    else if(m[x][y] == 10){
        if(!vis[x][y - 1] && y - 1 >= 1)ret += dfs(x, y - 1);
        if(!vis[x][y + 1] && y + 1 <= M)ret += dfs(x, y + 1);
    }
    else if(m[x][y] == 12){
        if(!vis[x - 1][y] && x - 1 >= 1)ret += dfs(x - 1, y);
        if(!vis[x][y - 1] && y - 1 >= 1)ret += dfs(x, y - 1);
    }
    else if(m[x][y] == 7){
        if(!vis[x + 1][y] && x + 1 <= N)ret += dfs(x + 1, y);
    }
    else if(m[x][y] == 11){
        if(!vis[x][y + 1] && y + 1 <= M)ret += dfs(x, y + 1);
    }
    else if(m[x][y] == 13){
        if(!vis[x - 1][y] && x - 1 >= 1)ret += dfs(x - 1, y);
    }
    else if(m[x][y] == 14){
        if(!vis[x][y - 1] && y - 1 >= 1)ret += dfs(x, y - 1);
    }
    else if(m[x][y] == 15){
    }
    return ret;
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++){
        cin >> m[i][j];
    }
    int cnt = 0;
    int mx = 0;
    for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++){
        if(!vis[i][j]){
            ++cnt;
            mx = max(mx, dfs(i, j));
        }
    }
    cout << cnt << endl;
    cout << mx << endl;
    return 0;
}