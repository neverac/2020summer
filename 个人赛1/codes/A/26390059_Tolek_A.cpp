#include <bits/stdc++.h>
using namespace std;
int op[2005], n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", op + i);
    sort(op + 1, op + n + 1);
    int ans = 0;
    for (int i = 1; i <= k; i++) ans += op[i];
    printf("%d", ans);
    return 0;
}