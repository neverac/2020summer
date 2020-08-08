#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
int m, a[15];
ll n;
ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int main()
{
    scanf("%lld%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", a + i);
    ll ans = 0;
    for (int i = 1; i < (1 << m); i++) {
        int num = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) ++num;
        }
        ll tmp = -1;
        for (int j = 0; j < m; j++) {
            if (!(i & (1 << j))) continue;
            if (tmp == -1) {
                tmp = a[j];
            } else {
                tmp = tmp * a[j] / gcd(tmp, a[j]);
            }
            if (tmp > n) goto to;
        }
        ans += n / tmp * ((num & 1) ? 1 : -1);
    // cout << tmp << endl;
    // cout << (n / tmp * ((num & 1) ? 1 : -1)) << endl;
    to:;
    }
    printf("%lld", ans);
    return 0;
}