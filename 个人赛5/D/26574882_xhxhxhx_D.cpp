#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

typedef long long ll;

int main()
{
    int t, n, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        ll lb = 0, rb = INT_MAX;
        while (lb + 1 < rb)
        {
            ll mid = (lb + rb) >> 1;
            ll cnt = (mid / n) * (n - 1) + mid % n;
            if (cnt < k)
            {
                lb = mid;
            }
            else
            {
                rb = mid;
            }
        }
        printf("%lld\n", rb);
    }
    return 0;
}