#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define dow(i,j,k) for(int i = j; i >= k; i--)
#define ez(i,j) for(int i = h[j]; i; i = e[i].next)
#define fi first
#define se second
using namespace std;


typedef long long ll;
typedef pair<int,int> pi;

const int N = 8e5 + 100;
int top[N], sz[N], fa[N], son[N], h[N], dep[N];
int ver[N], col[N];
int tag[N];
int dfn[N], tot, pos[N];
int cnt = 1, n, m;
struct edge{
	int to,next;
}e[N << 1];
struct node{
	int val, l, r;
}t[N << 2];

inline void add(int from,int to) {
	e[++cnt] = (edge){to, h[from]}; h[from] = cnt;
	e[++cnt] = (edge){from, h[to]}; h[to] = cnt;
}
void push_down(int x) {
    if (tag[x] == -1) return ;
    tag[x<<1] = tag[x<<1|1] = tag[x];
    t[x<<1].val = tag[x] * (t[x<<1].r - t[x<<1].l + 1);
    t[x<<1|1].val = tag[x] * (t[x<<1|1].r - t[x<<1|1].l + 1);
    tag[x] = -1;
}

void modify(int x,int l, int r, int v) {
    if (t[x].l > r || t[x].r < l) return;
    if (l <= t[x].l && t[x].r <= r) {
        t[x].val = v * (t[x].r - t[x].l+1);
        tag[x] = v;
        return;
    }
    push_down(x);
	modify(x << 1, l, r, v);
	modify(x << 1 | 1, l, r, v);
}

int query(int x,int l, int r) {
	if (l > t[x].r || r < t[x].l) return 0;
	if (l <= t[x].l && t[x].r <= r) return t[x].val;
    push_down(x);
	return query(x << 1, l, r) + query(x << 1 | 1, l, r);
}

void dfs1(int x) {
//	cout << "111 " << x << endl;
	sz[x] = 1;
	ez(i,x) {
		int v = e[i].to;
		if (!sz[v]) {
			ver[i/2] = v;
			dep[v] = dep[x] + 1;
			dfs1(v);
			fa[v] = x;
			sz[x] += sz[v];
			if (sz[v] > sz[son[x]]) son[x] = v;
		}
	}
}

void dfs2(int x,int f) {
//	cout << "222 " << x << endl;
	dfn[++tot] = x;
	pos[x] = tot;
	top[x] = f;
	if (son[x]) dfs2(son[x], f);
	ez(i,x) {
		int v = e[i].to;
		if (fa[v] == x && son[x] != v) {
			dfs2(v, v);
		}
	}
}

void build(int x,int l, int r) {
	t[x].l = l, t[x].r = r;
	if (l == r) {
        tag[x] = -1;
        return;
    }
	int mid = l + r >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r); 
}


void solve(int u) {
    while (top[u] != 1) {
        modify(1,pos[top[u]], pos[u], 0);
        u = fa[top[u]];
    }
    modify(1, 1, pos[u], 0);
}
int main() {
	scanf("%d", &n);
	rep(i,1,n-1) {
		int u, v;
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	dep[1] = 1;
	dfs1(1);
	dfs2(1, 1);
//	cout << "dfs finish" << endl;
	build(1,1,n);
	scanf("%d", &m);
	rep(i,1,m) {
		int op, u;
		scanf("%d", &op);
		switch(op) {
			case 1: scanf("%d", &u); modify(1,pos[u], pos[u] + sz[u]-1, 1);break;
			case 2: scanf("%d", &u); solve(u); break;
			case 3: scanf("%d", &u); printf("%d\n", query(1, pos[u], pos[u]));break;
		}
	}
}
