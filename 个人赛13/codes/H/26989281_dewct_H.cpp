#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll mm[550][550];
ll L[550], R[550];

inline ll read()
{
    ll r = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        r = (r << 3) + (r << 1) + (ch ^ 48);
        ch = getchar();
    }
    return r * w;
}

inline ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int n, m, k;
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            mm[i][j] = read(), mm[i][j] %= mod;
    }
    ll ans = 0;
    while (k--)
    {
        ll x, t;
        char s[10];
        scanf("%s", s);
        x = read();
        t = read();
        if (s[0] == 'r')
            R[x] = max(R[x], t);
        else
            L[x] = max(L[x], t);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans = ans + (max(R[i], L[j]) % mod) * mm[i][j] % mod;
            ans %= mod;
        }
    }
    ans = (ans + mod) % mod;
    //ans;
    printf("%lld\n", ans);
    return 0;
}