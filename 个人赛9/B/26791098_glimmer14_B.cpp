#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 100;

int h[N], to[N * 2], ne[N * 2], cnt;

void add(int u, int v)
{
    cnt ++;
    to[cnt] = v;
    ne[cnt] = h[u];
    h[u] = cnt;
}

int val[N];

int dfs(int r, int deep, int fa)
{
    // cout << r << endl;
    int son = 1;
    for (int i = h[r]; i; i = ne[i])
        if (to[i] != fa)
            son += dfs(to[i], deep + 1, r);
    val[r] = deep - son;
    return son;
}

int main()
{
    int n, k, u, v;
    cin >> n >> k;
    for (int i = 1; i < n; i ++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 1, 0);
    sort(val + 1, val + 1 + n);
    ll ans = 0;
    // for (int i = 1; i <= n; i ++)
    //     cout << val[i] << " ";
    for (int i = 0; i < k; i ++)
        ans += val[n - i];
    cout << ans << endl;
}