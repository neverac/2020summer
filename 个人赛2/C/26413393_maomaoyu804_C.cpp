#include <bits/stdc++.h>
#define ull unchaed long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back

#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)


using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 1e6 + 10;
char s[30];
ll d[30], f[30], n;
ll num(int x, int y)
{
    ll sum = 0;
    rep(i, x, y) sum = sum * 10 + s[i] - '0';
    return sum;
}
int main()
{
    int T = read();
    rep(Cas, 1, T)
    {
        memset(d, 0, sizeof(d));
        memset(f, 0x3f3f3f3f, sizeof(f));
        scanf("%s", s);
        n = strlen(s);
        rep0(i, n - 3)
            rep0(j, i)
                d[i] = max(d[i], num(0, j) + num(j + 1, i));
        rrep(i, n - 1, 2)
            rep(j, i, n - 1)
                rep(k, j + 1, n - 2)
                    f[i] = min(f[i], num(i, j) * num(j + 1, k) / num(k + 1, n - 1));
        ll ans = -100000000;
        rep(i, 1, n - 4) ans = max(ans, d[i] - f[i + 1]);
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}
