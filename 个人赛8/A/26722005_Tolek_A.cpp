#include <bits/stdc++.h>

#define N (500000 + 5)
using namespace std;
struct
{
    int to, next;
} edge[N << 1];
int head[N], father[N], son[N], sz[N];
int top[N], depth[N], cnt = 1, dCnt = 1, n, m;
int id[N], rk[N], init[N], tree[N << 1], lazy[N << 1];

inline void add(int x, int y)
{
    edge[cnt].to = y, edge[cnt].next = head[x], head[x] = cnt++;
}

void DFS1(int x, int fa)
{
    int maxn = -1, r = -1;
    for (int i = head[x]; i; i = edge[i].next) {
        if (edge[i].to != fa) {
            father[edge[i].to] = x, depth[edge[i].to] = depth[x] + 1, DFS1(edge[i].to, x), sz[x] += sz[edge[i].to];
            if (sz[edge[i].to] > maxn) maxn = sz[edge[i].to], r = edge[i].to;
        }
    }
    son[x] = r, sz[x]++;
}

void DFS2(int x, int t)
{
    id[x] = dCnt, rk[dCnt] = x, dCnt++, top[x] = t;
    if (sz[x] == 1) return;
    if (son[x]) DFS2(son[x], t);
    for (int i = head[x]; i; i = edge[i].next) {
        if (edge[i].to != son[x] && edge[i].to != father[x]) DFS2(edge[i].to, edge[i].to);
    }
}

inline void down(int k, int l, int r)
{
    if (lazy[k] == -1) return;
    lazy[k << 1] = lazy[k << 1 | 1] = lazy[k];
    int mid = (l + r) >> 1;
    if (lazy[k] == 0) {
        tree[k << 1] = tree[k << 1 | 1] = 0;
    } else {
        tree[k << 1] = mid - l + 1;
        tree[k << 1 | 1] = r - mid;
    }
    lazy[k] = -1;
}

int query(int x, int l = 1, int r = n, int k = 1)
{
    if (l == r) return tree[k];
    down(k, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) return query(x, l, mid, k << 1);
    return query(x, mid + 1, r, k << 1 | 1);
}

void change(int x, int y, int v, int l = 1, int r = n, int k = 1)
{
    // cout << x << " " << y << endl;
    if (l >= x && r <= y) {
        tree[k] = v ? r - l + 1 : 0, lazy[k] = v;
        return;
    }
    down(k, l, r);
    int mid = (l + r) >> 1;
    if (y <= mid)
        change(x, y, v, l, mid, k << 1);
    else if (x > mid)
        change(x, y, v, mid + 1, r, k << 1 | 1);
    else
        change(x, mid, v, l, mid, k << 1), change(mid + 1, y, v, mid + 1, r, k << 1 | 1);
    tree[k] = tree[k << 1] + tree[k << 1 | 1];
}

inline void modify(int x, int y, int s)
{
    int tx = top[x], ty = top[y];
    while (tx != ty) {
        if (depth[tx] >= depth[ty]) {
            change(id[tx], id[x], s);
            x = father[tx], tx = top[x];
        } else {
            change(id[ty], id[y], s);
            y = father[ty], ty = top[y];
        }
    }
    if (depth[x] <= depth[y])
        change(id[x], id[y], s);
    else
        change(id[y], id[x], s);
}
int main()
{
    // DEBUG;
    scanf("%d", &n), memset(lazy, -1, sizeof(lazy));
    for (int i = 1, x, y; i < n; i++) scanf("%d%d", &x, &y), add(x, y), add(y, x);
    depth[1] = 1, DFS1(1, 0), DFS2(1, 1);
    int q;
    scanf("%d", &q);
    // cout << id[3] << endl;
    while (q--) {
        int c, v;
        scanf("%d%d", &c, &v);
        if (c == 1) {
            // cout << id[v] << " " << id[v] + sz[v] - 1 << endl;
            change(id[v], id[v] + sz[v] - 1, 1);
        } else if (c == 2) {
            modify(1, v, 0);
        } else {
            printf("%d\n", query(id[v]));
        }
        // cout << tree[1] << endl;
    }
    return 0;
}