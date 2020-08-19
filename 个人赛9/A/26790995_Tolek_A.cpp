#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
typedef long long ll;
int op[N], n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= (n << 1); i++) scanf("%d", op + i);
    sort(op + 1, op + 2 * n + 1);
    ll ans = 1ll << 60;
    for (int i = n + 1; i < 2 * n; i++) ans = min(ans, 1ll * (op[i] - op[i - n + 1]) * (op[2 * n] - op[1]));
    ans = min(ans, 1ll * (op[n] - op[1]) * (op[2 * n] - op[n + 1]));
    printf("%lld", ans);
    return 0;
}