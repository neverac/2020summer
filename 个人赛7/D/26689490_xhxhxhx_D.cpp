#include <cstdio>
using namespace std;

typedef long long ll;

const int factors[4] = {2, 3, 5, 7};

int main()
{
    ll A;
    int N;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%lld", &A);
        int cnt[4] = {0, 0, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            ll tmp = A;
            while (tmp % factors[i] == 0)
            {
                tmp /= factors[i];
                ++cnt[i];
            }
        }
        ll ans = 0, sum1 = 1;
        for (int i1 = cnt[1]; i1 >= 0; i1--)
        {
            ll sum2 = sum1;
            for (int i2 = cnt[2]; i2 >= 0; i2--)
            {
                ll sum3 = sum2;
                for (int i3 = cnt[3]; i3 >= 0; i3--)
                {
                    ans += sum3;
                    sum3 *= factors[3];
                }
                sum2 *= factors[2];
            }
            sum1 *= factors[1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}