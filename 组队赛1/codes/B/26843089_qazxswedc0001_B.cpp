#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
typedef long long ll;
int dp[N][N], op[N], n;
unordered_map<ll, int> mmp;
int DP(int x, int y)
{
    if (~dp[x][y]) return dp[x][y];
    ll d = op[y] - op[x], nxt = op[y] + d;
    if (mmp.count(nxt) == 0 || mmp[nxt] <= y) return dp[x][y] = 2;
    return dp[x][y] = DP(y, mmp[nxt]) + 1;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", op + i);
    sort(op + 1, op + n + 1);
    for (int i = 1; i <= n; i++) mmp[op[i]] = i;
    int ans = 2;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) ans = max(ans, DP(i, j));
    }
    printf("%d", ans);
    return 0;
}