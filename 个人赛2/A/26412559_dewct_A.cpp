#include <bits/stdc++.h>
using namespace std;

int vis[3000];
int fa[3000];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    for (int i = 1; i <= 3000; i++)
        fa[i] = i;
    int n, m;
    cin >> n >> m;
    int ls;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ls;
            int p = (i - 1) * m + j;
            if (ls == 0)
            {
                fa[find(p - m)] = find(p);
                fa[find(p + m)] = find(p);
                fa[find(p + 1)] = find(p);
                fa[find(p - 1)] = find(p);
            }
            if (ls == 1)
            {
                fa[find(p - m)] = find(p);
                fa[find(p + m)] = find(p);
                fa[find(p + 1)] = find(p);
            }
            if (ls == 2)
            {
                fa[find(p - 1)] = find(p);
                fa[find(p + m)] = find(p);
                fa[find(p + 1)] = find(p);
            }
            if (ls == 3)
            {
                fa[find(p + m)] = find(p);
                fa[find(p + 1)] = find(p);
            }
            if (ls == 4)
            {
                fa[find(p - m)] = find(p);
                fa[find(p - 1)] = find(p);
                fa[find(p + m)] = find(p);
            }
            if (ls == 5)
            {
                fa[find(p - m)] = find(p);
                fa[find(p + m)] = find(p);
            }
            if (ls == 6)
            {
                fa[find(p - 1)] = find(p);
                fa[find(p + m)] = find(p);
            }
            if (ls == 7)
            {
                fa[find(p + m)] = find(p);
            }
            if (ls == 8)
            {
                fa[find(p - m)] = find(p);
                fa[find(p - 1)] = find(p);
                fa[find(p + 1)] = find(p);
            }
            if (ls == 9)
            {
                fa[find(p - m)] = find(p);
                fa[find(p + 1)] = find(p);
            }
            if (ls == 10)
            {
                fa[find(p - 1)] = find(p);
                fa[find(p + 1)] = find(p);
            }
            if (ls == 11)
            {
                fa[find(p + 1)] = find(p);
            }
            if (ls == 12)
            {
                fa[find(p - m)] = find(p);
                fa[find(p - 1)] = find(p);
            }
            if (ls == 13)
            {
                fa[find(p - m)] = find(p);
            }
            if (ls == 14)
            {
                fa[find(p - 1)] = find(p);
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n * m; i++)
    {
        if (!vis[i])
        {
            ans1++;
            int ls = 1;
            vis[i] = 1;
            for (int j = i + 1; j <= n * m; j++)
            {
                if (find(i) == find(j) && !vis[j])
                    vis[j] = 1, ls++;
            }
            ans2 = max(ans2, ls);
        }
    }
    cout << ans1 << endl
         << ans2;
    return 0;
}