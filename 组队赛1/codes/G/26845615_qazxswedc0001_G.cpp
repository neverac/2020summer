#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
typedef long long ll;
int op[N], n, tr[N], pre[N], nxt[N];
inline void add(int x)
{
    for (int i = x; i <= 200000; i += i & -i) ++tr[i];
}
inline int sum(int x)
{
    int s = 0;
    for (int i = x; i >= 1; i -= i & -i) s += tr[i];
    return s;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", op + i);
    for (int i = 1; i <= n; i++) pre[i] = i - 1 - sum(op[i]), add(op[i]);
    memset(tr, 0, sizeof(tr));
    for (int i = n; i >= 1; i--) nxt[i] = n - i - sum(op[i]), add(op[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += min(pre[i], nxt[i]);
    printf("%lld", ans);
    return 0;
}