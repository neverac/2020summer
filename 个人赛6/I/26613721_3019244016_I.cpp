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

const int N = 3e5 + 100;
int top[N], sz[N], fa[N], son[N], h[N], dep[N];
int ver[N], col[N];
int dfn[N], tot, pos[N];
int cnt = 1, n, m;
struct edge{
	int to,next,val;
}e[N << 1];
struct node{
	int val, l, r;
}t[N << 2];
void pushup(int x) {
    t[x].val = max(t[x<<1].val, t[x<<1|1].val);
}
inline void add(int from,int to, int val) {
	e[++cnt] = (edge){to, h[from], val}; h[from] = cnt;
	e[++cnt] = (edge){from, h[to], val}; h[to] = cnt;
}

void modify(int x,int p, int v) {
	if (t[x].l == t[x].r) {
        t[x].val = v;
        return ;
    }
    int mid = t[x].l + t[x].r >> 1;
	if (p <= mid) modify(x << 1, p, v);
	else modify(x << 1 | 1, p, v);
    pushup(x);
}

int query(int x,int l, int r) {
	if (l > t[x].r || r < t[x].l) return 0;
	if (l <= t[x].l && t[x].r <= r) return t[x].val;
	return max(query(x << 1, l, r), query(x << 1 | 1, l, r));
}

void dfs1(int x) {
//	cout << "111 " << x << endl;
	sz[x] = 1;
	ez(i,x) {
		int v = e[i].to;
		if (!sz[v]) {
			ver[i/2] = v;
			dep[v] = dep[x] + 1;
            col[v] = e[i].val;
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
        t[x].val = col[dfn[l]];
        return;
    }
	int mid = l + r >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r); 
    pushup(x);
}


void solve(int u, int v) {
	int x = u, y = v;
	int dis = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		dis = max(dis, query(1, pos[top[x]], pos[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	dis =max(dis, query(1, pos[x]+1 , pos[y]));
    printf("%d\n", dis);
	//return x;
}

void solve(){
    memset(h, 0, sizeof(h));
    cnt = 1 ;
    memset(fa, 0, sizeof(fa));
    memset(t, 0, sizeof(t));
    tot = 0;
    memset(sz, 0, sizeof(sz));
    memset(top, 0, sizeof(top));
    memset(son, 0, sizeof(son));
	scanf("%d", &n);
	rep(i,1,n-1) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	dep[1] = 1;
	dfs1(1);
	dfs2(1, 1);
//	cout << "dfs finish" << endl;
	build(1,1,n);
	while(1) {
		int u, v;
        char op[20];
		scanf("%s", op);
        if (op[0] == 'D') break;
		switch(op[0]) {
			case 'C': scanf("%d%d", &u,&v); modify(1, pos[ver[u]], v); break;
			case 'Q': scanf("%d %d", &u, &v); solve(u, v);break;
		}
	}
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}

