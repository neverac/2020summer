#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
typedef long long ll;
int op[N], n;
ll sum[N], minn[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll ans = -(1ll << 60);
        for (int i = 1; i <= n; i++) scanf("%d", op + i), sum[i] = sum[i - 1] + op[i];
        for (int i = 1; i <= n; i++) minn[i] = min(minn[i - 1], sum[i]);
        for (int i = 1; i < n; i++) ans = max(ans, sum[i] - minn[i - 1]);
        for (int i = 1; i <= n; i++) ans = max(ans, sum[n] - sum[i]);
        // cout << ans << endl;
        if (ans < sum[n]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}