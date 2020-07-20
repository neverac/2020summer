#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

ll c1, c2, x, y;
bool can(const ll mid);

int main()
{

    scanf("%lld%lld%lld%lld", &c1, &c2, &x, &y);

    ll lb = 1, rb = 1e15;
    while (lb + 1 < rb)
    {
        ll mid = (lb + rb) >> 1;
        if (can(mid))
        {
            rb = mid;
        }
        else
        {
            lb = mid;
        }
    }
    printf("%lld\n", rb);

    return 0;
}

bool can(const ll mid)
{
    ll cnt1 = mid - mid / x, cnt2 = mid - mid / y, cnt3 = mid - mid / (x * y);
    return cnt1 >= c1 && cnt2 >= c2 && cnt3 >= (c1 + c2);
}