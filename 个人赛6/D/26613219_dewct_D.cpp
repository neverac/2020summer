#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL sum[105][105][15];
int main()
{
    ios::sync_with_stdio(false);
    int n, q, c;
    cin >> n >> q >> c;
    for (int i = 1; i <= n; i++)
    {
        int x, y, cc;
        cin >> x >> y >> cc;
        sum[x][y][cc] += 1;
    }
    for (int k = 0; k <= c; k++)
    {
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= q; i++)
    {
        ans = 0;
        LL t;
        int x1, x2, y1, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        LL ls = 0;
        for (int k = 0; k <= c; k++)
        {
            ls = sum[x2][y2][k] - sum[x1 - 1][y2][k] - sum[x2][y1 - 1][k] + sum[x1 - 1][y1 - 1][k];
            // cout << ls << " " << k << " " << sum[x2][y2][k] << endl;
            ans += ((k + t) % (c + 1)) * ls;
        }
        cout << ans << endl;
    }
    return 0;
}