#include <bits/stdc++.h>
using namespace std;
const int N = 10000000 + 5, mod = 998244353;
typedef long long ll;
int sta[N], b[N], ans[N], bk[N], n, p, x, y, z, top;
inline int add(int x)
{
    while (top && b[sta[top - 1]] >= b[x]) --top;
    int tp = 0;
    if (top) tp = sta[top - 1];
    sta[top++] = x;
    return tp;
}
int main()
{
    int tot = 0;
    scanf("%d%d%d%d%d%d", &n, &p, &x, &y, &z, b + 1);
    bk[1] = tot = ans[1] = b[1], add(1);
    for (int i = 2; i <= n; i++) {
        b[i] = (1ll * x * ans[i - 1] % p + 1ll * y * b[i - 1] % p + z) % p;
        int tp = add(i);
        bk[i] = (bk[tp] + 1ll * (i - tp) * b[i] % mod) % mod;
        ans[i] = (ans[i - 1] + bk[i]) % mod;
        tot ^= ans[i];
    }
    printf("%d", tot);
    return 0;
}