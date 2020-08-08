#include <bits/stdc++.h>
using namespace std;
inline int readint() {
	int f = 1, n = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch <= '9'&&ch >= '0') {
		n = (n << 1) + (n << 3) + ch - '0';
		ch = getchar();
	}
	return f*n;
}
const int maxn = 10000 + 10;

int fir[maxn], np[maxn << 1], ne[maxn << 1], ve[maxn << 1], Ecnt = 0;
inline void add(int u, int v, int w) {
	Ecnt++;
	np[Ecnt] = v;
	ne[Ecnt] = fir[u];
	ve[Ecnt] = w;
	fir[u] = Ecnt;
}
inline void ins(int u, int v, int w) {
	add(u, v, w);
	add(v, u, w);
}

int fa[maxn], dep[maxn], son[maxn], siz[maxn], val[maxn], num[maxn];
void dfs1(int u) {
	siz[u] = 1;
	son[u] = 0;
	int v;
	for (int i = fir[u]; i; i = ne[i]) {
		v = np[i];
		if (v == fa[u]) continue;
		dep[v] = dep[u] + 1;
		fa[v] = u;
		val[v] = ve[i];
		dfs1(v);
		siz[u] += siz[v];
		if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
	}
}
int top[maxn], has[maxn], Tcnt = 0;
void dfs2(int u) {
	has[u] = ++Tcnt;
	num[Tcnt] = val[u];
	if (!son[u]) return;
	top[son[u]] = top[u];
	dfs2(son[u]);
	int v;
	for (int i = fir[u]; i; i = ne[i]) {
		v = np[i];
		if (v == fa[u] || v == son[u]) continue;
		top[v] = v;
		dfs2(v);
	}
}

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int Max[maxn<<2];
inline void PushUp(int rt) {
	Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
}
void build(int l, int r, int rt) {
	if (l == r) {
		Max[rt] = num[l];
		return;
	}
	int mid = l + r >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void Change(int w, int v, int l, int r, int rt) {
	if (l == r) {
		Max[rt] = v;
		return;
	}
	int mid = l + r >> 1;
	if (w <= mid) Change(w, v, lson);
	else Change(w, v, rson);
	PushUp(rt);
}
int QueryMax(int L, int R, int l, int r, int rt) {
	if (L <= l&&r <= R) return Max[rt];
	int mid = l + r >> 1, ret = -(1 << 30);
	if (L <= mid) ret = max(ret, QueryMax(L, R, lson));
	if (R > mid) ret = max(ret, QueryMax(L, R, rson));
	return ret;
}

void QMAX(int x, int y) {
	int ret = -(1 << 30);
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ret = max(ret, QueryMax(has[top[x]], has[x], 1, Tcnt, 1));
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) swap(x, y);
	ret = max(ret, QueryMax(has[y] + 1, has[x], 1, Tcnt, 1));
	printf("%d\n", ret);
}
int ui[maxn], vi[maxn], wi[maxn];
int main() {
	int T = readint();
	while(T--){
		int n = readint();
		for (int i = 1; i < n; i++) {
			ui[i] = readint();
			vi[i] = readint();
			wi[i] = readint();
			ins(ui[i], vi[i], wi[i]);
		}
		fa[1] = 0;
		dfs1(1);
		top[1] = 1;
		dfs2(1);
		build(1, Tcnt, 1);
		char opt[10];
		int a, b;
		while(scanf("%s", opt) != EOF){
			if(opt[0] == 'D') break;
			else if(opt[0] == 'Q'){
				a = readint();
				b = readint();
				QMAX(a, b);
			}
			else{
				a = readint();
				wi[a] = readint();
				if(dep[ui[a]] > dep[vi[a]]){
					Change(has[ui[a]], wi[a], 1, Tcnt, 1);
				}
				else{
					Change(has[vi[a]], wi[a], 1, Tcnt, 1);
				}
			}
		}
		for(int i = 1; i <= n; i++) fir[i] = 0;
		Ecnt = Tcnt = 0;
	}
	return 0;
}