#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[200550];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> num[i];
    }
    sort(num + 1, num + n * 2 + 1);
    ll ans = (num[n] - num[1]) * (num[2 * n] - num[n + 1]);
    for (int i = 1; i <= n; i++)
    {
        ans = min((num[2 * n] - num[1]) * (num[i + n] - num[i + 1]), ans);
    }
    cout << ans << endl;
    return 0;
}