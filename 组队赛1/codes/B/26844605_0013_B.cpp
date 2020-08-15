#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5005;

struct C{
    int x;
    int u, v;
}c[N*N/2];
int n, a[N];
int h[N], vis[N], dep[N];
int ans = 1;
int cnt, tot;

struct edge{
    int to, next;
}e[N*N/2];



void add(int u, int v) {
    e[++tot] = (edge) {v, h[u]}; h[u] = tot;
}

bool cmp (C x, C y) {
    if (x.x != y.x) return x.x < y.x;
    if (x.u != y.u) return x.u < y.u;
    return x.v < y.v;
}

void dfs(int x) {
    vis[x] = 1;
    for (int i = h[x]; i; i = e[i].next) {
        int v = e[i].to;
        if (vis[v]) continue;
        dep[v] = dep[x] + 1;
        dfs(v);
    }
    ans = max(ans, dep[x] + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i<= n;i++) cin >>a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            c[++cnt] = {abs(a[i] - a[j]), i, j};
        }
    }
    sort(c + 1, c + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++) {
        int j = i;
        while (j + 1 <= cnt && c[j+1].x == c[i].x) j++;
tot = 0;
        for (int k = i; k <= j; k++) h[c[k].u] = h[c[k].v] = vis[c[k].u] = vis[c[k].v] = dep[c[k].u] = dep[c[k].v] = 0;
        for (int k = i; k <= j; k++) add(c[k].u, c[k].v);
        for (int k = i; k <= j; k++) if (!vis[c[k].u]) dfs(c[k].u);
        i = j;
    }
    cout << ans << endl;
}