#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 100;
ll val[N], n;

int main()
{
    cin >> n;
    for (int i = 1; i <= 2 * n; i ++)
        cin >> val[i];
    sort(val + 1, val + 2 * n + 1);
    ll ans = (val[n] - val[1]) * (val[2 * n] - val[n + 1]);
    // cout << ans << endl;
    for (int i = 2; i <= n; i ++)
        ans = min(ans, (val[2 * n] - val[1]) * (val[i + n - 1] - val[i]));
    cout << ans << endl;
}