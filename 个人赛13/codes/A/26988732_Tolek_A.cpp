#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
ll x, y;

int main()
{
    ll n, m, T;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
        if (y >= x) {
            printf("%lld\n", m);
            continue;
        }
        ll cnt = (n - x) / (x - y) + 1;
        if (m <= cnt) {
            printf("%lld\n", m);
            continue;
        }
        m -= cnt;
        n -= cnt * (x - y);
        n += m * y;
        if (n / x != (n - y) / x)
            cnt += (n - y) / x;
        else
            cnt += n / x;
        printf("%lld\n", cnt);
    }
    return 0;
}