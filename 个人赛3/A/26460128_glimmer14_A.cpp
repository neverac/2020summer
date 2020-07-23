#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int head[N], ne[N], from[N], to[N], cnt;
int d[N];

void add(int u, int v)
{
    cnt ++;
    from[cnt] = u;
    to[cnt] = v;
    ne[cnt] = head[u];
    head[u] = cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
        cin >> u >> v, add(u, v), d[v] ++;
    
    queue<int> q;
    int cc  = 0;
    for (int i = 1; i <= n; i ++)
        if (d[i] == 0) q.push(i), cc++;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = ne[i])
        {
            int v = to[i];
            d[v] --;
            if (d[v] == 0)
                q.push(v), cc ++;
        }
    }

    if (cc == n)
    {
        cout << 1 << endl;
        for (int i = 1; i <= m; i ++)
            cout << 1 << " ";
        cout << endl;
    }
    else
    {
        cout << 2 << endl;
        for (int i = 1; i <= m; i ++)
            cout << (from[i] < to[i]) + 1 << " ";
        cout << endl;
    }

}
