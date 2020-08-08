#include<bits/stdc++.h>
using namespace std;
#define N 110
int g[11][N][N];
int s[11][N][N];
int x[100010], y[100010], o[100010];
int n, q, c;

void init(){
    cin>>n>>q>>c;
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &x[i], &y[i], &o[i]);
        // g[0][x][y] = z;
        // for(int i = 1; i <= c; i++){
        //     int p = (z + i) % (c + 1);
        //     g[i][x][y] = p;
        // }
    }
    for(int i = 1; i <= n; i++){
        for(int t = 0; t <= c; t++){
            g[t][x[i]][y[i]] += ((o[i] + t) % (c + 1));
        }
    }
    for(int t = 0; t <= c; t++){
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++) s[t][i][j] = s[t][i][j - 1] + g[t][i][j];
        }
    }
    return ;
}

void solve(){
    while(q--){
        int x1, y1, x2, y2, t;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        t %= (c + 1);
        int ans = 0;
        for(int i = x1; i <= x2; i++) ans += s[t][i][y2] - s[t][i][y1 - 1];
        printf("%d\n", ans);
    }
    return ;
}

int main(){
    init();
    solve();
    return 0;
}