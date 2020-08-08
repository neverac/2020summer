#include<bits/stdc++.h>
using namespace std;

const int maxn = 200050;

int fst[maxn], nxt[maxn], tot = 0;
bool used[maxn], vis[maxn];
int dfn[maxn], low[maxn];
int stacks[maxn], size[maxn], scc = 0, cnt = 0;
int ss[maxn];
struct qer
{
    int f, t;
}es[maxn];

void build(int f, int t)
{
    es[++tot] = (qer){ f, t };
    nxt[tot] = fst[f];
    fst[f] = tot;
}

void dfs(int x)
{
    vis[x] = 1;
    for (int i = fst[x]; i; i = nxt[i])
    {
        int v = es[i].t;
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int stop =0, dindex = 0, bcnt = 0;
int instack[maxn];
int belong[maxn];
int stap[maxn];
stack <int> S;
void tarjan(int v) {
    int u;//l = vec[v].size();
    dfn[v] = low[v] = ++dindex;
    instack[v] = true;
    stap[++stop] = v;
    for (int i = fst[v]; i; i=nxt[i]) {
        u = es[i].t;
        if (!dfn[u]) {
            tarjan(u);
            if (low[u] < low[v])
                low[v] = low[u];
        }
        else if (instack[u] && dfn[u] < low[v])
            low[v] = dfn[u];
    }
    if (dfn[v] == low[v]) {
        bcnt++;
        do {
            u = stap[stop--];
            instack[u] = false;
            belong[u] = bcnt;
        } while (u != v);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        build(u, v);
    }
    int rt;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            rt = i;
        }
    }
    memset(vis, 0, sizeof(vis));
    dfs(rt);
    bool flag = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            flag = 1;
    if (flag)
    {
        puts("0");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
                tarjan(i);
            // cout << belong[i] << endl;
        }
        for (int i = 1; i <= n; i++)
            size[belong[i]]++;
        cout << size[belong[rt]] << endl;
    }
    return 0;
}

/*
4 4
1 2
2 3
3 1
3 4
*/