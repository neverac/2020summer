#include <algorithm>
#include <cstdio>
using namespace std;

using ll = long long;

const int MAX_N = 100008;

int B[MAX_N], G[MAX_N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", B + i);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", G + i);
    }
    sort(B, B + n);
    sort(G, G + m);
    ll ans = 0;
    if (B[n - 1] > G[0])
    {
        ans = -1;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            ans += (ll)m * B[i];
        }
        for (int i = 0; i < m; i++)
        {
            ans += G[i];
        }
        if (B[n - 1] < G[0])
        {
            ans += B[n - 1] - B[n - 2];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
