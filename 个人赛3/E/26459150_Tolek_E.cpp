#include <bits/stdc++.h>
using namespace std;
int n, a[100005], b[100005];
long long dp[100005][2];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1] + a[i], max(dp[i - 1][0], dp[i - 1][1]));
        dp[i][1] = max(dp[i - 1][0] + b[i], max(dp[i - 1][0], dp[i - 1][1]));
    }
    printf("%lld", max(dp[n][0], dp[n][1]));
    return 0;
}