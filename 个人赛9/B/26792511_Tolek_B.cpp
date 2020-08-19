#include <bits/stdc++.h>
#define N (200000 + 5)
using namespace std;
struct
{
    int to, next;
} edge[N * 2];
int head[N], father[N], son[N], sz[N];
int top[N], depth[N], cnt = 1, dCnt = 1, n, m;
int id[N], rk[N], init[N], tree[N << 2], who[N << 2], lazy[N << 2];

inline void add(int x, int y)
{
    edge[cnt].to = y, edge[cnt].next = head[x], head[x] = cnt++;
}

void DFS1(int x, int fa)
{
    int maxn = -1, r = -1;
    for (int i = head[x]; i; i = edge[i].next) {
        if (edge[i].to != fa) {
            father[edge[i].to] = x, depth[edge[i].to] = depth[x] + 1;
            DFS1(edge[i].to, x), sz[x] += sz[edge[i].to];
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
inline void update(int k)
{
    if (tree[k << 1] >= tree[k << 1 | 1]) tree[k] = tree[k << 1], who[k] = who[k << 1];
    if (tree[k << 1] < tree[k << 1 | 1]) tree[k] = tree[k << 1 | 1], who[k] = who[k << 1 | 1];
    // cout << k << " " << tree[k] << " " << who[k] << endl;
}
void make(int l, int r, int k)
{
    if (l == r) {
        tree[k] = depth[rk[l]] - 1, who[k] = rk[l];
        return;
    }
    int mid = (l + r) >> 1;
    make(l, mid, 2 * k), make(mid + 1, r, 2 * k + 1), update(k);
}

inline void down(int k)
{
    if (lazy[k] == 0) return;
    tree[k << 1] += lazy[k], lazy[k << 1] += lazy[k];
    // cout << k << endl;
    tree[k << 1 | 1] += lazy[k], lazy[k << 1 | 1] += lazy[k];
    lazy[k] = 0;
}

void change(int x, int y, int l, int r, int s, int k)
{
    int mid = (l + r) >> 1;
    if (l >= x && r <= y) {
        tree[k] += s, lazy[k] += s;
        // cout << tree[k] << " " << lazy[k] << " ";
        // for (int i = x; i <= y; i++) cout << rk[i] << " ";
        // cout << endl;
        return;
    }
    down(k);
    if (mid + 1 <= x)
        change(x, y, mid + 1, r, s, 2 * k + 1);
    else if (mid >= y)
        change(x, y, l, mid, s, 2 * k);
    else
        change(x, mid, l, mid, s, 2 * k), change(mid + 1, y, mid + 1, r, s, 2 * k + 1);
    update(k);
}
int query(int x, int l = 1, int r = n, int k = 1)
{
    int mid = (l + r) >> 1;
    down(k);
    if (l == r) return tree[k];
    if (mid + 1 <= x) return query(x, mid + 1, r, 2 * k + 1);
    return query(x, l, mid, 2 * k);
}
inline void addL(int x, int y, int s)
{
    int tx = top[x], ty = top[y];
    while (tx != ty) {
        if (depth[tx] >= depth[ty]) {
            change(id[tx], id[x], 1, n, s, 1);
            x = father[tx], tx = top[x];
        } else {
            change(id[ty], id[y], 1, n, s, 1);
            y = father[ty], ty = top[y];
        }
    }
    if (depth[x] <= depth[y])
        change(id[x], id[y], 1, n, s, 1);
    else
        change(id[y], id[x], 1, n, s, 1);
}

int main()
{
    int ps;
    scanf("%d%d", &n, &ps);
    for (int i = 1, x, y; i < n; i++) scanf("%d%d", &x, &y), add(x, y), add(y, x);
    depth[1] = 1, DFS1(1, 0), DFS2(1, 1), make(1, n, 1);
    // for (int i = 1; i <= n; i++) cout << "DFN " << i << " " << id[i] << endl;
    // addL(1, 6, -1), addL(1, 16, -1);
    // cout << query(id[13]) << endl;
    // addL(6, 6, -1000000), addL(16, 16, -1000000), addL(19, 19, -1000000);
    // cout << tree[1] << " " << who[1] << endl;
    long long ans = 0;
    while (ps--) {
        ans += tree[1];
        int tmp = who[1];
        // cout << "ss" << tree[1] << " " << who[1] << " " << id[who[1]] << endl;
        addL(1, tmp, -1);
        addL(tmp, tmp, -1000000);
    }
    printf("%lld", ans);
    return 0;
}//////