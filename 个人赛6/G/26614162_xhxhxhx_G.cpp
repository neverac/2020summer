#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll ans = 0;
    while (b)
    {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    printf("%lld\n", ans);
    return 0;
}