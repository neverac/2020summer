#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX_N = 200088;

struct P
{
    int x;
    int y;
    P()
    {
    }
    P(int x, int y) : x(x), y(y)
    {
    }
    bool operator<(const P &R) const
    {
        return x < R.x || x == R.x && y < R.y;
    }
} p[MAX_N];

int main()
{
    ll s;
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%lld", &n, &s);
        for (int i = 0; i < n; i++)
        {
            P &cur = p[i];
            scanf("%d%d", &cur.x, &cur.y);
        }
        sort(p, p + n);
        int lb = 1, rb = 1e9 + 1;
        while (lb + 1 < rb)
        {
            int mid = (lb + rb) >> 1;
            if ([&]() {
                    ll sum = 0;
                    int cnt = 0;
                    for (int i = n - 1; i >= 0; i--)
                    {
                        if (p[i].x > mid)
                        {
                            sum += p[i].x;
                            ++cnt;
                        }
                        else if (cnt * 2 < n && p[i].y >= mid)
                        {
                            sum += mid;
                            ++cnt;
                        }
                        else
                        {
                            sum += p[i].x;
                        }
                    }
                    return cnt * 2 > n && sum <= s;
                }())
            {
                lb = mid;
            }
            else
            {
                rb = mid;
            }
        }
        printf("%d\n", lb);
    }
    return 0;
}