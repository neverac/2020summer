#include <bits/stdc++.h>
using namespace std;

bool vis[1050][1050];
int n, m;
char mm[1050][1050];
int xx[5] = {0, 0, 0, -1, 1};
int yy[5] = {0, 1, -1, 0, 0};

struct qer
{
    int x, y, d;
};

queue<qer> q;

int bfs()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (mm[i][j] == '1')
                q.push((qer){i, j, 1}), vis[i][j] = 1;
    }
    int ans = 214748;
    while (!q.empty())
    {
        qer u = q.front();
        if (mm[u.x][u.y] == '2')
            ans = min(ans, u.d);
        q.pop();
        for (int i = 1; i <= 4; i++)
        {
            int lx = u.x + xx[i];
            int ly = u.y + yy[i];
            int ld = u.d + 1;
            if (lx < 1 || lx > n || ly < 1 || ly > m || vis[lx][ly])
                continue;
            vis[lx][ly] = 1;
            q.push((qer){lx, ly, ld});
            // cout << 233 << endl;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", mm[i] + 1);
    }
    cout << bfs() << endl;
    return 0;
}