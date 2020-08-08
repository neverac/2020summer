#include <bits/stdc++.h>

const int maxn = 5e5 + 100;
using namespace std;
int a[maxn], n;
int to[maxn << 1], fst[maxn], nxt[maxn << 1], cnt;// w[maxn << 1], fr[maxn << 1];
int dep[maxn], son[maxn], siz[maxn], faz[maxn], rk[maxn];
int dfn[maxn], top[maxn], Index;
int t[maxn << 2], cov[maxn << 2], tag[maxn << 2];

void addedge(int u, int v) {
    to[++cnt] = v;
    nxt[cnt] = fst[u];
    fst[u] = cnt;
}

void dfs1(int u) {
    siz[u] = 1;
    son[u] = 0;
    for (int i = fst[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == faz[u]) continue;
        faz[v] = u;
        dep[v] = dep[u] + 1;
//        rk[v] = w[i];
        dfs1(v);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u, int rt) {
    dfn[u] = ++Index;
    top[u] = rt;
    rk[Index] = u;
//    a[Index] = rk[u];
    if (son[u]) dfs2(son[u], rt);
    for (int i = fst[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == faz[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void PushUp(int rt) {
    t[rt] = max(t[rt << 1], t[rt << 1 | 1]);
}

void PushDown(int rt) {
    if (~cov[rt]) {
        cov[rt << 1] = cov[rt << 1 | 1] = cov[rt];
        t[rt << 1] = t[rt << 1 | 1] = cov[rt];
        tag[rt << 1] = tag[rt << 1 | 1] = 0;
        cov[rt] = -1;
    }
    tag[rt << 1] += tag[rt];
    tag[rt << 1 | 1] += tag[rt];
    t[rt << 1] += tag[rt];
    t[rt << 1 | 1] += tag[rt];
    tag[rt] = 0;
}

void BuildSegmentTree(int rt, int l, int r) {
    cov[rt] = -1;
    if (l == r) {
        t[rt] = a[rk[l]];
        return;
    }
    int mid = l + r >> 1;
    BuildSegmentTree(rt << 1, l, mid);
    BuildSegmentTree(rt << 1 | 1, mid + 1, r);
    PushUp(rt);
}

void ModifyCover(int rt, int l, int r, int tl, int tr, int val) {
    if (tl <= l && r <= tr) {
        t[rt] = cov[rt] = val;
        tag[rt] = 0;
        return;
    }
    PushDown(rt);
    int mid = l + r >> 1;
    if (tl <= mid) ModifyCover(rt << 1, l, mid, tl, tr, val);
    if (tr > mid) ModifyCover(rt << 1 | 1, mid + 1, r, tl, tr, val);
    PushUp(rt);
}

void ModifyAdd(int rt, int l, int r, int tl, int tr, int val) {
    if (tl <= l && r <= tr) {
        t[rt] += val;
        tag[rt] += val;
        return;
    }
    PushDown(rt);
    int mid = l + r >> 1;
    if (tl <= mid) ModifyAdd(rt << 1, l, mid, tl, tr, val);
    if (tr > mid) ModifyAdd(rt << 1 | 1, mid + 1, r, tl, tr, val);
    PushUp(rt);
}

void ModifyCoverOnTree(int u, int v, int val) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ModifyCover(1, 1, n, dfn[top[u]], dfn[u], val);
        u = faz[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ModifyCover(1, 1, n, dfn[u], dfn[v], val);
}

int Query(int rt, int l, int r, int tl, int tr) {
    if (tl <= l && tr >= r) return t[rt];
    PushDown(rt);//!!!
    int mid = l + r >> 1, res = 0;
    if (tl <= mid) res = max(res, Query(rt << 1, l, mid, tl, tr));
    if (tr > mid) res = max(res, Query(rt << 1 | 1, mid + 1, r, tl, tr));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    dfs1(1);
    dfs2(1, 1);
    BuildSegmentTree(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        int opt;
        cin >> opt;
        cin >> x;
        if (opt == 1) {
//            int u = fr[x], v = to[x];
//            if (dep[u] > dep[v]) swap(u, v);
//            ModifyCoverOnTree(dfn[], v, y);
            ModifyCover(1,1,n,dfn[x],dfn[x]+siz[x]-1,1);
        }
        if (opt == 2) {
//            cin >> z;
            ModifyCoverOnTree(1, x, 0);
        }
        if (opt == 3) {

            cout << Query(1,1,n,dfn[x],dfn[x])<<endl;
        }
    }
}
