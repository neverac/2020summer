#include <bits/stdc++.h>

using namespace std;
int n, m, cnt;
const int maxn = 1e5 + 100;
struct node {
    int u, v;
} a[maxn << 1];
int faz[maxn],p[maxn];

int getfaz(int n) {
    if (faz[n] == n) return n;
    else return faz[n] = getfaz(faz[n]);
}

bool cmp(node a,node b){
    if (a.v == b.v) return a.u<b.u;
    else return a.v<b.v;
}
inline void init(){
    for (int i=1;i<=n;i++) faz[i] = i;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        a[++cnt].u = x;
        a[cnt].v = y;
    }

    sort(a+1,a+1+cnt,cmp);
    init();
    int t = 0;
    for (int i=1;i<=cnt;i++){
        int l =getfaz(a[i].u),r =getfaz(a[i].v);
        if (l == r) continue;
        faz[l] = r;
        t++;
        p[a[i].u] ++;
        p[a[i].v]++;
        if (t == n-1) break;
    }
    int res = 0;
    for (int i=1;i<=n;i++) res = max(res, p[i]);
    cout << res << endl;
}