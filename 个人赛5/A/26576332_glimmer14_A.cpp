#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll phi(ll n)
{
    ll ans = n, m = n;
    int lim = sqrt(n) + 1;
    for (int i = 2; i <= lim; i++)
    {
        if (m % i == 0)
        {
            ans -= ans / i;
            while (m % i == 0)
                m /= i;
        }
    }
    if (m > 1)
        ans -= ans / m;
    return ans;
}

ll qpow(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}


ll dfs(ll n, ll mod)
{
    if (mod == 1)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2 % mod;
    ll pp = phi(mod);
    return qpow(n, dfs(n - 1, pp) + pp, mod);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    // while (cin >> n >> m)
        cout << dfs(n, m) << endl;

    return 0;
}
