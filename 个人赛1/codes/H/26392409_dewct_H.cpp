#include <bits/stdc++.h>
using namespace std;

const int maxn = 200050;

int du[maxn];
int tot = 0;
int fst[maxn], nxt[maxn * 6];
bool used[maxn];
struct qer
{
    int f, t;
} es[maxn * 6];

queue<int> q;

void addedge(int f, int t)
{
    es[++tot] = (qer){f, t};
    nxt[tot] = fst[f];
    fst[f] = tot;
    es[++tot] = (qer){t, f};
    nxt[tot] = fst[t];
    fst[t] = tot;
}

void dfs(int s)
{
    q.push(s);
    used[s] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        printf("%d ", t);
        for (int i = fst[t]; i; i = nxt[i])
        {
            int v = es[i].t;
            if (!used[v])
            {
                du[v]--;
                if (du[v] == 1)
                {
                    q.push(v);
                    used[v] = 1;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 2; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addedge(a, b);
        addedge(a, c);
        addedge(b, c);
        du[a]++, du[b]++, du[c]++;
    }
    int s = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] == 1)
        {
            if (!s)
                s = i;
            else
                du[i] = 3;
        }
    }
    for (int i = fst[s]; i; i = nxt[i])
    {
        int v = es[i].t;
        if (du[v] == 2)
            s2 = v;
    }
    for (int i = 1; i <= n; i++)
    {
        if (du[i] == 2 && i != s2)
            du[i]++;
    }
    dfs(s);
    return 0;
}