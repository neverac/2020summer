#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5500];
ll f[5050][5050];
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
ll maxx(ll x, ll y) { return (x > y) ? x : y; }
int main()
{
    ll n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            f[i][j] = 2;
    }
    for (int i = n; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
        {
            int k = lower_bound(a + 1, a + n + 1, 2 * a[j] - a[i]) - a;
            if (k >= 1 && k <= n && a[k] - a[j] == a[j] - a[i])
                f[i][j] = max(f[i][j], f[j][k] + 1);
        }
    ll haha = -1;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            haha = maxx(haha, f[i][j]);
    cout << haha << endl;
    return 0;
}