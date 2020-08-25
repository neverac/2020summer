#include <bits/stdc++.h>
using namespace std;

const int N = 510;
typedef long long ll;
const ll mod = 998244353;

ll val[N][N], row[N], col[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> val[i][j], val[i][j] %= mod;

    ll x, t;
    char ch;
    while (q--)
    {
        cin >> ch >> x >> t;
        ch == 'r' ? row[x] = t: col[x] = t;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = (ans + max(row[i], col[j]) % mod * val[i][j]) % mod;
    cout << ans << endl;
    return 0;
}
