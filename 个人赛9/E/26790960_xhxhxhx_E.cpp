#include <cstdio>
using namespace std;

typedef unsigned long long ull;

ull gcd(ull x, ull y);
ull euler_phi(ull n);

int main()
{
    ull a, m;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%llu%llu", &a, &m);
        printf("%llu\n", euler_phi(m / gcd(a, m)));
    }
    return 0;
}

ull gcd(ull x, ull y)
{
    while (y)
    {
        ull tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

ull euler_phi(ull n)
{
    ull res = n;
    for (ull i = 2; i * i <= n; i++)
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