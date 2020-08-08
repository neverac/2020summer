#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
typedef long long ll;
int op[N], n, dp1[N], dp2[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", op + i);
    dp1[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (op[i] > op[i - 1])
            dp1[i] = dp1[i - 1] + 1;
        else
            dp1[i] = 1;
    }
    dp2[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        if (op[i] < op[i + 1])
            dp2[i] = dp2[i + 1] + 1;
        else
            dp2[i] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, max(dp1[i], dp2[i]));
    for (int i = 2; i < n; i++)
        if (op[i + 1] > op[i - 1]) ans = max(ans, dp1[i - 1] + dp2[i + 1]);
    printf("%d", ans);
    return 0;
}