#include <bits/stdc++.h>
using namespace std;
int b[100005], g[100005], n, m;
long long sum;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", b + i), sum += 1ll * b[i] * m;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= m; i++) scanf("%d", g + i);
    sort(g + 1, g + m + 1);
    for (int i = 1; i <= m; i++) {
        if (b[n - 1] > g[i] || g[i] < b[n]) {
            printf("-1");
            return 0;
        }
        sum += g[i] - b[n];
    }
    // cout << sum << endl;
    int minn = 0x7fffffff;
    for (int i = 1; i <= m; i++) minn = min(minn, g[i]);
    if (minn != b[n]) {
        if (n == 1) {
            printf("-1");
            return 0;
        }
        for (int i = 1; i <= m; i++) {
            if (b[n] <= g[i]) {
                sum += b[n] - b[n - 1];
                printf("%lld", sum);
                return 0;
            }
        }
        printf("-1");
    } else {
        printf("%lld", sum);
    }
    return 0;
}
