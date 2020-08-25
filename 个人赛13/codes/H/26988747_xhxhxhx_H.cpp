#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 512;

typedef long long ll;

ll A[MAX_N][MAX_N];
ll R[MAX_N], C[MAX_N];

int main()
{
    int n, m, k, x;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll &cur = A[i][j];
            scanf("%lld", &cur);
            cur %= MOD;
        }
    }
    ll t;
    for (char ch; k--;)
    {
        scanf(" \n%c%d%lld", &ch, &x, &t);
        --x;
        if (ch == 'r')
        {
            R[x] = max(R[x], t);
        }
        else
        {
            C[x] = max(C[x], t);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = (ans + max(R[i], C[j]) % MOD * A[i][j]) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}