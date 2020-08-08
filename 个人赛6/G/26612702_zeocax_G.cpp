#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
inline int readint()
{
    int ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll()
{
    ll ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
int main()
{
    ll a = readll(), b = readll();
    ll ans = a / b;
    a = a % b;
    while (a)
    {
        ans += b / a;
        ll la = a, lb = b;
        a = lb % la;
        b = la;
    }
    printf("%lld", ans);
    return 0;
}