#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll dp(ll a, ll b)
{
    if (a == 0) return 0;
    if (a >= b) return a / b + dp(a % b, b);
    swap(a, b);
    ll d = a / b;
    a %= b;
    if (a == 0) return d;
    return d + dp(b, a);
}
int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll d = gcd(a, b);
    a /= d, b /= d;
    printf("%lld\n", dp(a, b));
    return 0;
}