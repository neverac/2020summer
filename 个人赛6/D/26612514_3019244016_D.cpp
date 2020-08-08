#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,j,k) for (int i = j; i <= k; i++)
using namespace std;

int sum[105][105][12];
int n, q, c;

int main() {
    scanf("%d %d %d", &n, &q, &c);
    for (int i = 1; i <= n; i++) {
        int x, y, s;
        scanf("%d %d %d", &x, &y, &s);
        sum[x][y][s]++;
    }
    rep(i,1,100) rep(j,1,100) rep(s,0,c) {
        sum[i][j][s] = sum[i-1][j][s] + sum[i][j-1][s] - sum[i-1][j-1][s] + sum[i][j][s];
    }
    for (int i = 1; i<= q; i++) {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int ans = 0;
        rep(s, 0, c) {

            int res = sum[x2][y2][s] - sum[x2][y1-1][s] - sum[x1-1][y2][s] + sum[x1-1][y1-1][s];
            ans += ((s + t) % (c + 1)) * res;
        }
        printf("%d\n", ans);
    }
}