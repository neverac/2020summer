#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
vector<ll> yinzi, pr;
inline ll mu(ll x)
{
    ll ans = 1;
    for (int i = 0; i < pr.size(); i++) {
        if (x % pr[i]) continue;
        ans *= -1, x /= pr[i];
        while (x % pr[i] == 0) ans = 0, x /= pr[i];
    }
    return ans;
}
inline ll solve(ll x, ll y)
{
    ll ans = 0;
    for (int i = 0; i < yinzi.size(); i++) {
        if (y % yinzi[i]) continue;
        ans += mu(yinzi[i]) * (x / yinzi[i]);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll a, m, mm;
        scanf("%lld%lld", &a, &m);
        mm = m, yinzi.clear(), pr.clear();
        for (ll i = 1; i * i <= m; i++) {
            if (m % i == 0) {
                yinzi.push_back(i);
                if (m / i != i) yinzi.push_back(m / i);
            }
        }
        for (ll i = 2; i * i <= m; i++) {
            if (m % i == 0) {
                pr.push_back(i);
                while (m % i == 0) m /= i;
            }
        }
        if (m != 1) pr.push_back(m);
        m = mm;
        ll d = gcd(a, m);
        printf("%lld\n", solve((a + m - 1) / d, m / d) - solve((a - 1) / d, m / d));
    }
    return 0;
}