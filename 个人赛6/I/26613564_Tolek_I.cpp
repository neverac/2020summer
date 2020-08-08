#include <algorithm>
#include <cstdio>
#include <iostream>

#define N (30000 + 5)
using namespace std;
struct
{
    int to, next, v;
} edge[N * 2];
int head[N], father[N], son[N], sz[N];
int top[N], depth[N], cnt, dCnt, n;
int id[N], rk[N], init[N], tree[4 * N], gr[N][20];

inline void add(int x, int y, int v)
{
    edge[cnt].v = v, edge[cnt].to = y, edge[cnt].next = head[x], head[x] = cnt++;
}

void DFS1(int x, int fa)
{
    int maxn = -1, r = -1;
    for (int i = head[x]; i; i = edge[i].next) {
        if (edge[i].to != fa) {
            gr[edge[i].to][0] = x;
            for (int j = 1; j < 20; j++) gr[edge[i].to][j] = gr[gr[edge[i].to][j - 1]][j - 1];
            father[edge[i].to] = x, depth[edge[i].to] = depth[x] + 1, init[edge[i].to] = edge[i].v;
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
inline int LCA(int x, int y)
{
    while (top[x] != top[y]) {
        if (depth[father[top[x]]] > depth[father[top[y]]])
            x = father[top[x]];
        else
            y = father[top[y]];
    }
    return depth[x] < depth[y] ? x : y;
}

void make(int l, int r, int k)
{
    if (l == r) {
        tree[k] = init[rk[l]];
        return;
    }
    int mid = (l + r) >> 1;
    make(l, mid, k << 1), make(mid + 1, r, k << 1 | 1);
    tree[k] = max(tree[k << 1], tree[k << 1 | 1]);
}

int query(int x, int y, int l, int r, int k)
{
    int mid = (l + r) >> 1;
    if (l >= x && r <= y) return tree[k];
    if (mid < x) return query(x, y, mid + 1, r, k << 1 | 1);
    if (y <= mid) return query(x, y, l, mid, k << 1);
    return max(query(x, mid, l, mid, k << 1), query(mid + 1, y, mid + 1, r, k << 1 | 1));
}

void change(int x, int s, int l, int r, int k)
{
    int mid = (l + r) >> 1;
    if (l == r) {
        tree[k] = s;
        return;
    }
    if (x > mid)
        change(x, s, mid + 1, r, k << 1 | 1);
    else
        change(x, s, l, mid, k << 1);
    tree[k] = max(tree[k << 1], tree[k << 1 | 1]);
}

inline int queEdge(int x, int y)
{
    int tx = top[x], ty = top[y], ans = -0x3f3f3f3f;
    while (tx != ty) {
        if (depth[tx] >= depth[ty]) {
            ans = max(ans, query(id[tx], id[x], 1, n, 1));
            x = father[tx], tx = top[x];
        } else {
            ans = max(ans, query(id[ty], id[y], 1, n, 1));
            y = father[ty], ty = top[y];
        }
    }
    if (depth[x] <= depth[y]) return max(ans, query(id[x], id[y], 1, n, 1));
    return max(ans, query(id[y], id[x], 1, n, 1));
}
inline int getFa(int x, int to)
{
    for (int i = 19; i >= 0; i--) {
        if (depth[gr[x][i]] > depth[to]) x = gr[x][i];
    }
    return x;
}
char opt[10];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n), cnt = 1, dCnt = 1;
        for (int i = 1; i <= n; i++) head[i] = sz[i] = 0;
        for (int i = 1, a, b, c; i < n; i++) scanf("%d%d%d", &a, &b, &c), add(a, b, c), add(b, a, c);
        depth[1] = 1, DFS1(1, 0), DFS2(1, 1), make(1, n, 1);
        while (scanf("%s", opt)) {
            if (opt[0] == 'D') break;
            int a, b, lca, x, y, ans;
            if (opt[0] == 'Q') {
                scanf("%d%d", &a, &b);
                if (a == b) {
                    printf("0\n");
                    continue;
                }
                lca = LCA(a, b), ans = -0x3f3f3f3f;
                if (lca != a) ans = max(ans, queEdge(a, getFa(a, lca)));
                if (lca != b) ans = max(ans, queEdge(b, getFa(b, lca)));
                printf("%d\n", ans);
            } else {
                scanf("%d%d", &a, &b);
                x = edge[a << 1].to;
                y = edge[(a << 1) - 1].to;
                if (depth[x] > depth[y]) swap(x, y);
                change(id[y], b, 1, n, 1);
            }
        }
    }
    return 0;
}//////