#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
int n, m, k, op[501][501];
ll rr[501], cc[501];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        ll tmp;
        for (int j = 1; j <= m; j++) scanf("%lld", &tmp), op[i][j] = tmp % mod;
    }
    int ans = 0;
    while (k--) {
        char opt;
        int x;
        ll t;
        scanf(" %c%d%lld", &opt, &x, &t);
        if (opt == 'r') {
            rr[x] = t;
        } else {
            cc[x] = t;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) ans = (ans + max(rr[i], cc[j]) % mod * op[i][j] % mod) % mod;
    }
    printf("%d", ans);
    return 0;
}