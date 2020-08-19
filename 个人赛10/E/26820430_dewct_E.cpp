#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[200050];
ll dp[200050];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof dp);
        int n;
        ll p;
        int k;
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> num[i];
        }
        sort(num + 1, num + n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i >= k)
                dp[i] = min(dp[i - 1] + num[i], dp[i - k] + num[i]);
            else
                dp[i] = dp[i - 1] + num[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] <= p)
                ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}
