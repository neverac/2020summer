#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, m;
        cin >> a >> m;
        ll n = m / __gcd(a, m);
        ll ls = n;
        for (ll i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ls /= i;
                ls *= (i - 1);
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        if (n != 1)
            ls -= ls / n;
        cout << ls << endl;
    }
    return 0;
}