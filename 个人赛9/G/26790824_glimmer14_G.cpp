#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
struct Node
{
    int p, id;
    bool operator<(const Node &a) const
    {
        return p > a.p;
    }
};

priority_queue<Node> q[4];
bool vis[N];
int p[N];

int main()
{
    int n, m, c, a, b;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> a;
        q[a].push({p[i], i});
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> b;
        q[b].push({p[i], i});
    }

    cin >> m;
    while (m--)
    {
        cin >> c;
        while (!q[c].empty() && vis[q[c].top().id])
            q[c].pop();
        if (q[c].empty())
            cout << -1 << " ";
        else
        {
            cout << q[c].top().p << " ";
            vis[q[c].top().id] = true;
            q[c].pop();
        }
    }
}