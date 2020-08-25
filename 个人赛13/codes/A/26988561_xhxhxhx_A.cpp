#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t, n, m, x, y;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &n, &m, &x, &y);
        printf("%d\n", int(min<ll>((n + ll(m - 1) * y) / x, m)));
    }
    return 0;
}