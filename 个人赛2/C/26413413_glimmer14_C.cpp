#include <bits/stdc++.h>
using namespace std;

int val[30], n;

void read()
{
    n = 0;
    char ch = getchar();
    while (ch < '0') ch = getchar();
    while (ch >= '0') val[n++] = ch - '0', ch = getchar();
}

typedef long long ll;

ll pp(int a, int b)
{
    ll x = 0;
    for (int i = a; i <= b; i ++)
        x = x * 10 + val[i];
    return x;
}

inline ll p1(int a, int b)
{
    ll ans = LONG_LONG_MIN;
    for (int i = 0; i < 2; i ++)
    {
        if (a + i == b) break;
        ll t1 = pp(a, a + i) + pp(a + i + 1, b);
        ll t2 = pp(a, b - i - 1) + pp(b - i, b);
        ll tt = max(t1, t2);
        ans = max(ans, tt);
    }
    
    return ans;
}

inline ll p2(int a, int b)
{
    ll t1 = pp(a, a);
    ll t2 = pp(a + 1, a + 1);
    ll t3 = pp(a + 2, b);
    return t1 * t2 / t3;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i ++)
    // while (t--)
    {
        // read();
        string s;
        cin >> s;
        n = s.length();
        for (int i = 0; i < n; i ++)
            val[i] = s[i] - '0';
        ll ans = LONG_LONG_MIN;
        for (int i = 3; i <= 5; i ++)
        {
            if (n - i < 2) break;
            ll tt = p1(0, n - i - 1) - p2(n - i, n - 1);
            ans = max(ans, tt); 
        }
        // Case #1: 1
        printf("Case #%d: %lld\n", i, ans);
        // cout << ans << endl;
    }
}
