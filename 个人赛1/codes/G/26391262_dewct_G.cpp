#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL b[100050], g[100050];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
    }
    for (int i = 1; i <= m; i++)
        scanf("%lld", &g[i]);
    sort(b + 1, b + n + 1);
    sort(g + 1, g + m + 1);
    if (g[1] < b[n])
    {
        puts("-1");
    }
    else
    {
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += b[i];
        }
        ans *= m;
        for (int i = 2; i <= m; i++)
        {
            ans += g[i] - b[n];
        }
        if (g[1] != b[n])
            ans += g[1] - b[n - 1];
        cout << ans;
    }
    return 0;
}