#include <bits/stdc++.h>
using namespace std;

const int N = 100;
bool val[N][N][4];
bool vis[N][N];

int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};

int dfs(int x, int y)
{
    vis[x][y] = true;
    int ans = 1;
    for (int k = 0; k < 4; k ++)
    {
        if (val[x][y][k]) continue;
        int px = x + dir[k][0], py = y + dir[k][1];
        if (!vis[px][py]) ans += dfs(px, py); 
    }
    return ans;
}

int main()
{
    int n, m, tt;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            cin >> tt;
            for (int k = 0; k < 4; k ++)
                val[i][j][k] = tt & (1 << k);
        }
    
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (!vis[i][j])
            {
                cnt ++;
                ans = max(ans, dfs(i, j));
            }
    cout << cnt << endl;
    cout << ans << endl;
}
            