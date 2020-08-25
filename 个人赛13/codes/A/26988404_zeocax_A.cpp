#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
inline int readint()
{
    int ret = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}
inline ll readll()
{
    ll ret = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}
int main()
{
    int T = readint();
    while (T--)
    {
        ll n = readll(), m = readll(), x = readll(), y = readll();
        if (y >= x)
            printf("%lld\n", m);
        else
        {
            ll ans = (n + (m - 1) * y) / x;
            printf("%lld\n", min(ans, m));
        }
    }
    return 0;
}