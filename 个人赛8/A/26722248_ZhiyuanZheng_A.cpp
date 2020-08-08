#include <bits/stdc++.h>
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
const int maxn = 2 * 1e6 + 100;
//节点数，操作数，根节点序号，取模数
int n, m, r, p;
//父亲，重儿子，深度，子树元素数目
int fa[maxn], son[maxn], depth[maxn], num[maxn];
int counts = 0;
// 链上最顶层父亲节点，新的标号，值
int top[maxn], indextree[maxn], a[maxn];
int w[maxn];
//链式前向星
struct node {
    int u, v, nxt;
} edge[maxn];
int head[maxn];
int cnt = 1;
//线段树
struct tree {
    int l, r, w, size, lazy;
} s[maxn];
void addedge(int x, int y) {
    edge[cnt].u = x;
    edge[cnt].v = y;
    edge[cnt].nxt = head[x];
    head[x] = cnt ++;
}

void pushup(int rt) {
    s[rt].w = (s[ls].w + s[rs].w) ;
}
void pushdown(int rt) {
    if (s[rt].lazy != -1) {
        s[ls].w = s[rt].lazy;
        s[rs].w = s[rt].lazy;
        s[ls].lazy = s[rt].lazy;
        s[rs].lazy = s[rt].lazy;
        s[rt].lazy = -1;
    }
}
void build(int l, int r, int rt) {
    s[rt].l = l; s[rt].r = r; s[rt].size = r - l + 1;
    s[rt].lazy=-1;
    if (l == r) {
        s[rt].w = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    pushup(rt);
}

void nodeadd(int val, int L, int R, int rt) {
    pushdown(rt);
	if (L <= s[rt].l && R >= s[rt].r) {
        s[rt].w = val;
        s[rt].lazy = val;
        return;
    }
    pushdown(rt);
    int mid = (s[rt].l + s[rt].r) >> 1;
    if (L <= mid) nodeadd(val, L, R, ls);
    if (R > mid) nodeadd(val, L, R, rs);
    pushup(rt);
}

void pathadd(int l, int r, int val) {
    while (top[l] != top[r]) {
        if (depth[top[l]] < depth[top[r]]) swap(l, r);
        nodeadd(val, indextree[top[l]], indextree[l], 1);
        l = fa[top[l]];
    }
    if (depth[l] > depth[r]) swap(l, r);
    nodeadd(val, indextree[l], indextree[r], 1);
}
int nodesum(int L, int R, int rt) {
    pushdown(rt);
    if (L == s[rt].l && R == s[rt].r)
        return s[rt].w;
    int mid = (s[rt].l + s[rt].r) >> 1;
    if (L <= mid) return nodesum(L, R, ls);
    if (R > mid) return nodesum(L, R, rs);
}

int dfs1(int root, int f, int d) {
    depth[root] = d;
    fa[root] = f;
    num[root] = 1;
    int heavyson = -1;
    for (int i = head[root]; i != -1; i = edge[i].nxt) {
        if (edge[i].v == f) continue;
        num[root] += dfs1(edge[i].v, root, d + 1);
        if (num[edge[i].v] > heavyson) {
            heavyson = num[edge[i].v];
            son[root] = edge[i].v;
        }
    }
    return num[root];
}

void dfs2(int root, int tf) {
    indextree[root] = ++counts;
    top[root] = tf;
    a[counts] = w[root];
    if (son[root] == 0) return;
    dfs2(son[root], tf);
    for (int i = head[root]; i != -1; i = edge[i].nxt) {
        if (indextree[edge[i].v] == 0) dfs2(edge[i].v, edge[i].v);
    }
}

int main() {
    cin >> n;
	r=1;
    memset(head, -1, sizeof head);
    for (int i = 1; i <= n; i ++) w[i]=0;
    for (int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        addedge(a, b); addedge(b, a);
    }
    dfs1(r, 0, 1);
    dfs2(r, r);
    build(1, n, 1); //建树
	cin>>m;
    while (m--) {
        int opt, x;
        cin >> opt;
        switch (opt) {
        case 2: { //区间修改
            cin >> x;
            pathadd(1, x, 0);
            break;
        }
        case 1: { //单点修改
            cin >> x;
            nodeadd(1, indextree[x], indextree[x] + num[x] - 1, 1);
            break;
        }
        case 3: { //单点查询
            cin >> x;
            cout << nodesum(indextree[x],indextree[x],r) << endl;
            break;
        }
        }
    }
    return 0;
}