#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int sum[N][N][15];
typedef long long ll;

int main()
{
    int n, q, c, x, y, s;
    cin >> n >> q >> c;
    for (int i = 1; i <= n; i ++)
        cin >> x >> y >> s, sum[x][y][s] ++;
    

    for (int i = 1; i <= 100; i ++)
        for (int j = 1; j <= 100; j ++)
            for (int k = 0; k <= c; k ++)
                sum[i][j][k] += sum[i][j - 1][k];
    for (int i = 1; i <= 100; i ++)
        for (int j = 1; j <= 100; j ++)
            for (int k = 0; k <= c; k ++)
                sum[i][j][k] += sum[i - 1][j][k];
    
    int x1, x2, y1, y2, t;
    while (q--)
    {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll ans = 0;
        for (int k = 0; k <= c; k ++)
            ans += (k + t) % (c + 1) * (sum[x2][y2][k] - sum[x1 - 1][y2][k] - sum[x2][y1 - 1][k] + sum[x1 - 1][y1 - 1][k]);
        cout << ans << endl;
    }
    
}