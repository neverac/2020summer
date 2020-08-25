#include <bits/stdc++.h>
using namespace std;

int fa[100050];
int du[100050];

struct qer
{
    int f, t;
} es[200050];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool cmp(qer a, qer b)
{
    if (a.f == b.f)
        return a.t < b.t;
    return a.f < b.f;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int f, t;
        cin >> f >> t;
        es[i].f = max(f, t), es[i].t = min(f, t);
    }
    sort(es + 1, es + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int u = find(es[i].f), v = find(es[i].t);
        if (u != v)
        {
            du[es[i].f]++;
            du[es[i].t]++;
            fa[u] = v;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, du[i]);
    cout << ans;
    return 0;
}