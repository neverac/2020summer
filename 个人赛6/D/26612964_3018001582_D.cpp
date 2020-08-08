#include <bits/stdc++.h>
using namespace std;
int n, q, c;
int sum[105][105][15] = { 0 };

inline void init(){
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 0; k <= c; k++) {
                sum[i][j][k] += (sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k]);
            }
        }
    }
}

int main()
{
    int x, y, x1, y1, x2, y2, t, k;
    while (~scanf("%d%d%d", &n, &q, &c))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &k);
            sum[x][y][k]++;
        }
        init();
        for (int i = 0; i < q; i++)
        {
            scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
            int ans = 0;
            for (int i = 0; i <= c; i++)
            {
                ans += ((t + i) % (c + 1)) *( sum[x2][y2][i] + sum[x1 - 1][y1 - 1][i] - sum[x1 - 1][y2][i] - sum[x2][y1 - 1][i]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
