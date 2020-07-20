#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX_N = 64;

char ch[MAX_N];

int main()
{
    int T;
    scanf("%d", &T);
    for (int cc = 1; cc <= T; cc++)
    {
        scanf(" \n%s", ch);
        int len = strlen(ch);
        for (int i = 0; i < len; i++)
        {
            ch[i] -= '0';
        }
        ll a=0, b, c, d, e, ans = -1e18;
        e = ch[len - 1];
        d = ch[len - 2];
        c = ch[len - 3];
        b = ch[len - 4];
        for (int i = 0; i < len - 4; i++)
        {
            a = a * 10 + ch[i];
        }
        ans = max(ans, a + b - c * d / e);
        ll kk = 10;
        for (int i = len - 6; i >= 0; i--)
        {
            e += kk * d;
            d = c;
            c = b;
            b = ch[i + 1];
            a /= 10;
            kk *= 10;
            ans = max(ans, a + b - c * d / e);
        }
        kk /= 10;
        for (int i = 2; i + 3 < len; i++)
        {
            b = b * 10 + ch[i];
            c = d;
            d = e / kk;
            e %= kk;
            kk /= 10;
            ans = max(ans, a + b - c * d / e);
        }
        printf("Case #%d: %lld\n", cc, ans);
    }
    return 0;
}

/*

1
123456789

*/