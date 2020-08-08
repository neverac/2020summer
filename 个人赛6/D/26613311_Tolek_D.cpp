#include <bits/stdc++.h>
using namespace std;
int sum[150][150][20], n, q, c, vis[150][150], ld[150][150][20];
int main()
{
    scanf("%d%d%d", &n, &q, &c), ++c;
    for (int i = 1, x, y, z; i <= n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        vis[x][y] = 1;
        for (int j = 0; j < c; j++) ld[x][y][j] += (z + j) % c;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int z = 0; z < c; z++) {
                sum[i][j][z] = sum[i][j - 1][z] + (vis[i][j] ? ld[i][j][z] : 0);
            }
        }
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int z = 0; z < c; z++) sum[j][i][z] += sum[j - 1][i][z];
        }
    }
    while (q--) {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        t %= c;
        printf("%d\n", sum[x2][y2][t] - sum[x2][y1 - 1][t] - sum[x1 - 1][y2][t] + sum[x1 - 1][y1 - 1][t]);
    }
    return 0;
}