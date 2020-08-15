#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 16384;

int dp[MAX_N];

int dist(int r, int s, int x, int y);

int main()
{
    int r, s, p, x, y;
    scanf("%d%d%d", &r, &s, &p);
    int mxd = 0;
    for (int i = 0; i < p; i++)
    {
        scanf("%d%d", &x, &y);
        const int d = dist(r, s, x, y);
        mxd = max(mxd, d);
        ++dp[d];
    }

    int cur = 0, ans = 0;
    for (; ans <= mxd; ans++)
    {
        cur += dp[ans];
        if (cur)
        {
            --cur;
        }
    }
    --ans;
    ans += cur;
    printf("%d\n", ans);
    return 0;
}

inline int dist(int r, int s, int x, int y)
{
    if (y > s)
    {
        y = 2 * s - y + 1;
    }
    return s + 1 - y + r + 1 - x;
}

/*

5 2 7 1 1 1 2 1 3 2 3 2 4 4 4 5 2


500 500 16 1 1 1 2 1 999 1 1000 2 1 2 2 2 999 2 1000 3 1 3 2 3 999 3 1000 499 500 499 501 499 999 499 1000

*/