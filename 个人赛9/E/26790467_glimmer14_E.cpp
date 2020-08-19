#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    return (a ? gcd(b % a, a) : b);
}

ll euler(ll m)
{
    ll ans = m;
    for (ll i = 2; i * i <= m; i ++)
    {
        if (m % i == 0)
        {
            while (m % i == 0) m /= i;
            ans -= ans / i;
        }
    }
    if (m > 1) ans -= ans / m;
    return ans;
}

int main()
{
    ll t, a, m;
    cin >> t;
    while (t--)
    {
        cin >> a >> m;
        ll g = gcd(a, m);
        m /= g;
        cout << euler(m) << endl;
    }
}