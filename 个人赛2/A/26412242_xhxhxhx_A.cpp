#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 128;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

int G[MAX_N][MAX_N];
int dfs(int x, int y);

int main()
{
    int n, m, x;
    scanf("%d%d", &n, &m);
    n *= 2;
    m *= 2;
    for (int i = 1; i < n; i += 2)
    {
        for (int j = 1; j < m; j += 2)
        {
            scanf("%d", &x);
            for (int k = 0; k < 4; k++)
            {
                if (x >> k & 1)
                {
                    if (dx[k])
                    {
                        G[i + dx[k]][j] = G[i + dx[k]][j + 1] = G[i + dx[k]][j - 1] = -1;
                    }
                    else
                    {
                        G[i][j + dy[k]] = G[i + 1][j + dy[k]] = G[i - 1][j + dy[k]] = -1;
                    }
                }
            }
            G[i][j] = 1;
        }
    }

    int a = 0, b = 0;
    for (int i = 1; i < n; i += 2)
    {
        for (int j = 1; j < m; j += 2)
        {
            if (~G[i][j])
            {
                a++;
                b = std::max(b, dfs(i, j));
            }
        }
    }
    printf("%d\n%d\n", a, b);

    return 0;
}

int dfs(int x, int y)
{
    int cnt = G[x][y];
    G[x][y] = -1;
    for (int i = 0; i < 4; i++)
    {
        if (~G[x + dx[i]][y + dy[i]])
        {
            cnt += dfs(x + dx[i], y + dy[i]);
        }
    }
    return cnt;
}