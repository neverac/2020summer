#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll n, m, b[N], g[N];


int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < n; i ++)
        cin >> b[i], ans += b[i] * m;
    for (int i = 0; i < m; i ++)
        cin >> g[i];

    sort(b, b + n, greater<int>());
    sort(g, g + m, greater<int>());

    if (b[0] > g[m - 1])
    {
        cout << -1 << endl;
        return 0;
    }

    if (n == 1)
    {
        if (b[0] != g[0])
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
        return 0;
    }
    // for (int i = 0; i < n; i ++)
    //     cout << b[i] << " ";
    // for (int i = 0; i < m; i ++)
    //     cout << g[i] << " ";

    
    for (int i = 0; i < m - 1; i ++)
        ans += g[i] - b[0];
    if (g[m - 1] != b[0])
        ans += g[m - 1] - b[1];
    cout << ans << endl;
}