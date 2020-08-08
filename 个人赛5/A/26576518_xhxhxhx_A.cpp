#include <cstdio>
using namespace std;

typedef long long ll;

ll solve(ll x, ll m);
int euler_phi(int n);
ll mod_pow(ll x, ll p, const ll m);

int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", n == 1 ? 1 : solve(n, m));
    return 0;
}

ll solve(ll x, ll m)
{
    if (m == 1)
    {
        return 0;
    }
    if (x == 2)
    {
        return x % m;
    }
    int euler = euler_phi(m);
    return mod_pow(x, solve(x - 1, euler) + euler, m);
}

int euler_phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n != 1)
    {
        res = res / n * (n - 1);
    }
    return res;
}

ll mod_pow(ll x, ll p, const ll m)
{
    ll res = 1;
    x %= m;
    while (p)
    {
        if (p & 1)
        {
            res = res * x % m;
        }
        x = x * x % m;
        p >>= 1;
    }
    return res;
}