#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 200050;

int fst[maxn], nxt[maxn * 2], tot = 0;
bool used[maxn];

struct qer
{
    int f, t;
} es[maxn * 2];

struct qer2
{
    int sons, dep;
} dian[maxn];

void build(int f, int t)
{
    es[++tot] = (qer){f, t};
    nxt[tot] = fst[f];
    fst[f] = tot;
}

void dfs(int x)
{
    used[x] = 1;
    for (int i = fst[x]; i; i = nxt[i])
    {
        int v = es[i].t;
        if (!used[v])
        {
            dian[v].dep = dian[x].dep + 1;
            dfs(v);
            dian[x].sons += dian[v].sons + 1;
        }
    }
}

bool cmp(qer2 a, qer2 b)
{
    return a.dep - a.sons > b.dep - b.sons;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        build(u, v);
        build(v, u);
    }
    dian[1].dep = 0;
    dfs(1);
    sort(dian + 1, dian + n + 1, cmp);
    ll sum = 0;
    for (int i = 1; i <= k; i++)
        sum += (ll)(dian[i].dep - dian[i].sons);
    cout << sum << endl;
    return 0;
}