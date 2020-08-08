#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char val[N][N];
int vis[N][N];
const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

queue<int> q;

int n, m;
int bfs()
{
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        int x = now / n + 1, y = now % n + 1;
        // cout << x << " " << y << " " << vis[x][y] << endl;
        for (int k = 0; k < 4; k++)
        {
            int px = x + dir[k][0], py = y + dir[k][1];
            if (vis[px][py]) continue;
            vis[px][py] = vis[x][y] + 1;
            if (val[px][py] == '2')
            {
                // cout << px << " " << py << endl;
                return vis[px][py];
            }
            q.push((px - 1) * n + (py - 1));
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> val[i][j];
            if (val[i][j] == '1')
                q.push((i - 1) * n + (j - 1)), vis[i][j] = 1;
        }


    for (int i = 1; i <= n; i++)
        vis[i][0] = vis[i][m + 1] = 1;
    for (int j = 1; j <= m; j++)
        vis[0][j] = vis[n + 1][j] = 1;

    cout << bfs() << endl;
    return 0;
}