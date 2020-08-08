#include <bits/stdc++.h>
using namespace std;
int fa[100005], n, k, sz[100005];
int ff(int x)
{
    return fa[x] == x ? x : fa[x] = ff(fa[x]);
}
inline void merge(int x, int y)
{
    if (ff(x) == ff(y)) return;
    int f1 = ff(x), f2 = ff(y);
    fa[f1] = f2, sz[f2] += sz[f1];
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ff(i) == i) ans += sz[i] - 1;
    }
    printf("%d", k - ans);
    return 0;
}