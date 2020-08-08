#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll getEuler(ll x)
{
    ll euler = 1;
    for (ll i = 2; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
            x /= i, euler *= (i - 1);
            while (x % i == 0) x /= i, euler *= i;
        }
    }
    if (x > 1) euler *= x - 1;
    return euler;
}
const ll S[] = {0, 1, 2, 9, 1ll << 18};
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
inline ll qpow(ll x, ll y, ll mod)
{
    ll ans = 1, sta = x;
    while (y) {
        if (y & 1) ans = ans * sta % mod;
        sta = sta * sta % mod, y >>= 1;
    }
    return ans;
}
ll f(ll a, ll m)
{
    if (m == 1) return 0;
    if (a == 1) return 1;
    if (gcd(a, m) == 1) {
        return qpow(a, f(a - 1, getEuler(m)), m);
    } else if (a >= 5) {
        ll tmp = f(a - 1, getEuler(m)) + getEuler(m);
        return qpow(a, tmp, m);
    }
    return S[a] % m;
}
int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", f(n, m));
    return 0;
}