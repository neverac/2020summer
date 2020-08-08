#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
typedef long long ll;
char op[N];
int n, dp[N][10][10][2], num[10];
int DP(int x, int y, int z, int mod)
{
    if (x == n + 1) return 0;
    if (~dp[x][y][z][mod]) return dp[x][y][z][mod];
    if (mod == 0) {
        if (op[x] == '0' + y) return dp[x][y][z][mod] = max(DP(x + 1, y, z, 1) + 1, DP(x + 1, y, z, 0));
        return dp[x][y][z][mod] = DP(x + 1, y, z, 0);
    } else {
        if (op[x] == '0' + z) return dp[x][y][z][mod] = max(DP(x + 1, y, z, 0) + 1, DP(x + 1, y, z, 1));
        return dp[x][y][z][mod] = DP(x + 1, y, z, 1);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 10; i++) num[i] = 0;
        scanf("%s", op + 1);
        n = strlen(op + 1);
        for (int i = 1; i <= n; i++) ++num[op[i] - '0'];
        for (int i = 1; i <= n; i++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) dp[i][a][b][0] = dp[i][a][b][1] = -1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) ans = max(ans, num[i] & 1 ? num[i] : num[i] - 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                int sp = DP(i, op[i] - '0', j, 0);
                // cout << i << " " << j << " " << sp << endl;
                ans = max(ans, sp & 1 ? sp - 1 : sp);
            }
        }
        printf("%d\n", n - ans);
    }
    return 0;
}