#include <bits/stdc++.h>
using namespace std;

int du[5050];
int fst[23333], nxt[23333], tot = 0;
struct qer
{
    int f, t;
} es[23333];

queue<int> q;

void build(int f, int t)
{
    es[++tot] = (qer){f, t};
    nxt[tot] = fst[f];
    fst[f] = tot;
}

bool dfs(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!du[i])
            q.push(i), sum++;
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = fst[u]; i; i = nxt[i])
        {
            int v = es[i].t;
            du[v]--;
            if (!du[v])
            {
                q.push(v), sum++;
            }
        }
    }
    if (sum != n)
        return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int ff, tt;
        cin >> ff >> tt;
        build(ff, tt);
        du[tt]++;
    }
    if (dfs(n))
    {
        cout << 1 << endl;
        for (int i = 1; i <= tot; i++)
        {
            cout << 1 << " ";
        }
    }
    else
    {
        cout << 2 << endl;
        for (int i = 1; i <= tot; i++)
        {
            if (es[i].f < es[i].t)
            {
                cout << 1 << " ";
            }
            else
                cout << 2 << " ";
        }
    }
    return 0;
}