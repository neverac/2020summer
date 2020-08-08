#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m;

int e, beg[N], to[N << 1], ne[N << 1];
inline void add(int u, int v)
{
    to[++e] = v;
    ne[e] = beg[u];
    beg[u] = e;
}

//-------------------------------------- 以下为线段树
#define ls (root << 1)
#define rs (root << 1 | 1)
#define mid ((r + l) >> 1)
int sta[N << 2];

inline void push_down(int l, int r, int root)
{
    sta[ls] = sta[rs] = sta[root];
    sta[root] = -1;
}

void update(int a, int b, int l, int r, int root, int k)
{
    if (a <= l && r <= b)
    {
        sta[root] = k;
        return;
    }
    if (sta[root] != -1) push_down(l, r, root);
    if (a <= mid) update(a, b, l, mid, ls, k);
    if (b > mid) update(a, b, mid + 1, r, rs, k);
}

int query(int x, int l, int r, int root)
{
    if (sta[root] != -1) return sta[root];
    if (x <= mid) return query(x, l, mid, ls);
    else return query(x, mid + 1, r, rs);
}

//---------------------------------以上为线段树
#define sson to[i]
int deep[N], siz[N], son[N], fa[N], top[N];
int cnt, id[N];

void dfs1(int x)
{
    siz[x] = 1, deep[x] = deep[fa[x]] + 1;
    for (int i = beg[x]; i; i = ne[i])
    {
        if (sson == fa[x]) continue;
        fa[sson] = x;
        dfs1(sson);
        siz[x] += siz[sson];
        if (siz[son[x]] < siz[sson]) son[x] = sson;
    }
}

void dfs2(int x, int topp)
{
    id[x] = ++cnt;
    top[x] = topp;
    if (son[x]) dfs2(son[x], topp);
    for (int i = beg[x]; i; i = ne[i])
        if (sson != fa[x] && sson != son[x])
            dfs2(sson, sson);
}

// -------------------------------以上为树剖 dfs

int qPoint(int x)
{
    return query(id[x], 1, n, 1);
}

void upRange(int x, int y, int k)
{
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        update(id[top[x]], id[x], 1, n, 1, k);
        x = fa[top[x]];
    }
    if (deep[x] < deep[y]) swap(x, y);
    update(id[y], id[x], 1, n, 1, k);
}

inline void upSon(int x, int k)
{
    update(id[x], id[x] + siz[x] - 1, 1, n, 1, k);
}

// -----------------------------以上为树剖和线段树结合

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int u, v;
    cin >> n;
    for (int i = 1; i < n; i ++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    int r = 1;
    dfs1(r);
    dfs2(r, r);

    int m, a, b;
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        switch (a)
        {
        case 1:
            upSon(b, 1); break;
        case 2:
            upRange(b, r, 0); break;
        case 3:
            cout << qPoint(b) << endl; break;
        }
    }
}