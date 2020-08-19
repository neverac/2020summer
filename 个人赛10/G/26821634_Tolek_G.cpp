#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
typedef long long ll;
int n, a[N], m;
ll dp[N][N];
inline int solve(int l, ll ss, int d)
{
    int ans = 0x3f3f3f3f, pos;
    for (int i = l; i <= n; i++) {
        if (dp[i + 1][d - 1] == ss - a[i]) {
            if (a[i] < ans) ans = a[i], pos = i;
        }
    }
    return pos;
}
int main()
{
    // DEBUG;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    dp[n][0] = 0, dp[n][1] = a[n];
    for (int i = 2; i <= n; i++) dp[n][i] = -0x3f3f3f3f;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n; j++) dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1] + a[i]);
    }
    scanf("%d", &m);
    while (m--) {
        int k, pos;
        scanf("%d%d", &k, &pos);
        int at = 0;
        ll sum = dp[1][k];
        // cout << sum << endl;
        for (int i = 1; i <= pos; i++) at = solve(at + 1, sum, k - i + 1), sum -= a[at];
        printf("%d\n", a[at]);
    }
    return 0;
}