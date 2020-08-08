#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int MAX_N = 512;

int A[MAX_N], B[MAX_N];

int main()
{
    int n;
    scanf("%d", &n);
    A[0] = 1e6;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", A + i);
    }
    n = unique(A + 1, A + n + 1) - (A + 1);

    for (int i = 1; i <= n; i++)
    {
        B[i] = A[i] - A[i - 1];
    }
    B[n + 1] = -1e6;

    ll ans = 100, p = 0;
    for (int i = 1; i <= n; i++)
    {
        if (B[i] < 0 && B[i + 1] > 0)
        {
            p += ans / A[i];
            ans %= A[i];
            if (p > 100000)
            {
                ans += (ll)A[i] * (p - 100000);
                p = 100000;
            }
        }
        if (B[i] > 0 && B[i + 1] < 0)
        {
            ans += p * A[i];
            p = 0;
        }
    }
    if (p)
    {
        for (;;)
            ;
    }
    printf("%lld\n", ans);
    return 0;
}